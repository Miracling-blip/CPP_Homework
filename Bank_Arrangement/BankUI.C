#include <iostream>
#include <limits>
#include "BankUI.h"
#include "BankAccount.h"

// 输入失败(比如该读数字却读了字母)后必须清状态，否则后面所有 >> 全部直接跳过
static void resetInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

BankUI::BankUI() : isover(false)
{
}

void BankUI::run()
{
    while (!isover)
    {
        showMenu();
        if (askNewOrLogin())            // 'M'：开户
        {
            char copy;
            std::cout << "Copy an existing account as the new one(y/N)? ";
            if (!(std::cin >> copy)) { isover = true; break; }

            if (copy == 'y' || copy == 'Y') loginAccount();
            else                            mkAccount();
        }
        else                            // 'L'：登录（'Q' 时 askNewOrLogin 已置 isover）
        {
            if (isover) break;
            loginAccount();
        }
    }
    std::cout << "Bye.\n";
}

void BankUI::showMenu()
{
    std::cout << "\n==== Welcome to XX bank ====\n";
    std::cout << "M : create a new account\n";
    std::cout << "L : log in an existing account\n";
    std::cout << "Q : quit\n";
}

bool BankUI::askNewOrLogin()
{
    while (true)
    {
        char op;
        if (!(std::cin >> op)) { isover = true; return false; }   // Ctrl+D / EOF

        if (op == 'M' || op == 'm') return true;
        if (op == 'L' || op == 'l') return false;
        if (op == 'Q' || op == 'q') { isover = true; return false; }

        std::cerr << "Illegal input! Please input again.\n";
    }
}

int BankUI::mkAccount()
{
    while (true)
    {
        int password, confirm;
        std::cout << "The password must consist of PURE NUMBER!\n";
        std::cout << "Please set your password: ";
        if (!(std::cin >> password)) { resetInput(); return 0; }
        std::cout << "Please input again to confirm: ";
        if (!(std::cin >> confirm))  { resetInput(); return 0; }

        if (password != confirm)
        {
            std::cerr << "Unmatched!\n";
            continue;
        }

        accounts.push_back(BankAccount(password));   // 构造函数里自动领号
        accountNumber++;
        int id = accounts.back().getaccount();
        std::cout << "Successful! Your accountID is " << id << "\n";

        operateAccount(id, password);                // 开完户直接进入操作菜单
        return id;
    }
}

void BankUI::loginAccount()
{
    while (true)
    {
        int ID, pwd;
        std::cout << "Please input your accountID: ";
        if (!(std::cin >> ID)) { resetInput(); return; }

        // ID 从 1001 起，vector 下标从 0 起 —— 这个 -1001 是两套编号之间的桥。
        // 更稳的写法：用 find 按 ID 查，别让下标和账号绑死
        if (ID <= 1000 || ID - 1001 >= (int)accounts.size())
        {
            std::cerr << "NONEXISTING ACCOUNT!\n";
            return;         // 原来写 continue：查不到就永远出不去，改成回主菜单
        }

        std::cout << "Please input your password: ";
        if (!(std::cin >> pwd)) { resetInput(); return; }

        if (!accounts[ID - 1001].confirm(ID, pwd))
        {
            std::cerr << "WRONG PASSWORD!\n";
            return;
        }

        operateAccount(ID, pwd);
        return;
    }
}

// ↓↓↓ 你缺的就是这一块：拿到账户对象后，循环调用它的成员函数 ↓↓↓
void BankUI::operateAccount(int id, int pwd)
{
    // 必须是引用！写成 BankAccount acc = accounts[id-1001];
    // 就会拷出一个副本，存取款全改在副本上，vector 里那个原封不动
    BankAccount& acc = accounts[id - 1001];

    while (true)
    {
        std::cout << "\n--- Account " << id << " ---\n";
        std::cout << "D : deposit\nW : withdraw\nS : show\nQ : back\n";

        char op;
        if (!(std::cin >> op)) { resetInput(); return; }

        if (op == 'D' || op == 'd')
        {
            double amount;
            std::cout << "Amount: ";
            if (std::cin >> amount) acc.deposit(amount);
            else { std::cerr << "Not a number!\n"; resetInput(); }
        }
        else if (op == 'W' || op == 'w')
        {
            double amount;
            std::cout << "Amount: ";
            if (std::cin >> amount) acc.withdraw(amount, pwd);
            else { std::cerr << "Not a number!\n"; resetInput(); }
        }
        else if (op == 'S' || op == 's')
        {
            acc.display();
        }
        else if (op == 'Q' || op == 'q')
        {
            return;
        }
        else
        {
            std::cerr << "Illegal input!\n";
        }
    }
}
