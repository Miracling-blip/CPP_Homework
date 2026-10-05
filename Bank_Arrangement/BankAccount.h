#pragma once

// 头文件里没有用到 std::cout / std::cin，所以不需要 #include <iostream>
class BankAccount
{
public:
    BankAccount(int pwd);

    void deposit(double amount);
    bool withdraw(double amount, int pwd);

    bool confirm(int ID, int pwd) const;
    void display() const;

    int  getaccount() const;        // 原来放在 private：BankUI 取不到账号，编译不过
    static int getID();

private:
    inline static int sendID = 1000;   // 所有账户共享的发号器
    int        accountID;
    double     balance;
    const int  password;               // const 成员 -> 拷贝赋值运算符被隐式删除
};
