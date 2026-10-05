#include <iostream>
#include "BankAccount.h"

int BankAccount::getID()          // static 成员函数：没有 this，只能碰 static 成员
{
    sendID++;
    return sendID;
}

// 真正的初始化顺序 = 成员的声明顺序(accountID -> balance -> password)，
// 跟初始化列表的书写顺序无关；写成一致是为了关掉 -Wreorder 警告
BankAccount::BankAccount(int pwd)
    : accountID(getID()), balance(0.0), password(pwd)
{
}

int BankAccount::getaccount() const
{
    return accountID;
}

void BankAccount::deposit(double amount)
{
    if (amount >= 0) balance += amount;
    else std::cerr << "WRONG AMOUNT!\n";
}

bool BankAccount::withdraw(double amount, int pwd)
{
    if (pwd != password)
    {
        std::cerr << "WRONG PASSWORD!\n";
        return false;
    }
    if (amount > balance)
    {
        std::cerr << "Your balance is not enough!\n";
        return false;
    }
    balance -= amount;
    std::cout << "Done. Your balance is: " << balance << "\n";
    return true;
}

bool BankAccount::confirm(int ID, int pwd) const
{
    return ID == accountID && pwd == password;
}

void BankAccount::display() const
{
    std::cout << "ID: " << accountID << "\n";
    std::cout << "Balance: " << balance << "\n";
}
