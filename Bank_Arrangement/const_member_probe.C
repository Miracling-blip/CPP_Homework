#include <iostream>
#include <vector>
#include <utility>
#include "BankAccount.h"

// 编译： g++ -std=c++17 const_member_probe.C BankAccount.C -o probe
// 玩法：下面标 [开] 的行现在能编译；标 [关] 的行被注释掉了，
//       你一次只取消一行注释，编译，看报错原文，再注释回去。

int main()
{
    BankAccount a(111);
    BankAccount b(222);

    // ---------- 第 1 组：const 成员到底禁掉了什么 ----------
    BankAccount c = a;        // [开] 拷贝构造：能过
    BankAccount d(a);         // [开] 也是拷贝构造：能过
    // a = b;                 // [关] 取消注释 → 报错
    // c = a;                 // [关] 取消注释 → 报错（跟上一行同一个错）
    // std::swap(a, b);       // [关] 取消注释 → 报错（swap 内部就是赋值）

    // ---------- 第 2 组：vector 对这个类的容忍边界 ----------
    std::vector<BankAccount> v;
    v.push_back(BankAccount(1));    // [开] 能过：扩容只需要拷贝/移动"构造"
    v.push_back(BankAccount(2));    // [开] 能过
    v.emplace_back(3);              // [开] 能过
    // v[0] = v[1];                 // [关] 取消注释 → 报错
    // v.erase(v.begin());          // [关] 取消注释 → 报错（要把后面元素往前赋值）
    // v.insert(v.begin(), BankAccount(4)); // [关] 同理，报错

    // ---------- 第 3 组：static 发号器是全局共享、不随对象重置 ----------
    std::cout << "=== v 里的账户 ===\n";
    for (const BankAccount& acc : v) acc.display();   // 猜：ID 是 1001 1002 1003 吗？

    BankAccount x(1), y(2);
    std::cout << "=== 后建的 x, y ===\n";
    x.display();                    // 猜：ID 是 1001 吗？
    y.display();                    // 猜：ID 是 1002 吗？

    // ---------- 第 4 组：const 成员函数是给 const 对象用的 ----------
    const BankAccount e(5);
    e.display();                    // [开] 能过：display() 是 const 成员函数
    // e.deposit(10);               // [关] 取消注释 → 报错：deposit 不是 const
    // e.withdraw(10, 5);           // [关] 取消注释 → 报错：withdraw 不是 const

    // ---------- 第 5 组：deposit 的负数分支到底改没改余额 ----------
    std::vector<BankAccount> w;
    w.push_back(BankAccount(9));
    w[0].deposit(100);              // 先存 100
    w[0].deposit(-50);              // 再存 -50（应该被拒）
    w[0].display();                 // 猜：余额是 0 还是 100？
}
