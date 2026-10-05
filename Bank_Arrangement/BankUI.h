#pragma once
#include <vector>
#include "BankAccount.h"

// 头文件里不要写 using namespace std; 它会污染每一个包含这个头文件的 .C
class BankUI
{
public:
    BankUI();
    void run();

private:
    void showMenu();
    bool askNewOrLogin();               // true = 开户,  false = 登录
    int  mkAccount();
    void loginAccount();
    void operateAccount(int id, int pwd);   // 登录后调 BankAccount 成员函数的地方

    bool isover;                        // 类成员只放"跨函数共享的状态"
    inline static int accountNumber = 0;
    std::vector<BankAccount> accounts;      // BankUI has-a BankAccount（组合）
};
