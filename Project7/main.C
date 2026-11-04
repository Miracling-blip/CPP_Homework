#include "BigInt.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "=== 测试 1: 基础减法与符号翻转 ===" << endl;
    BigInt a("1000");
    BigInt b("999");
    BigInt c("-500");
    BigInt d("500");
    
    // 正 - 正
    cout << "1000 - 999 = " << (a - b) << " (期望 1)" << endl;
    
    // 正 - 负（相当于正 + 正）
    cout << "500 - -500 = " << (d - c) << " (期望 1000)" << endl;
    
    // 负 - 正（相当于负 + 负）
    cout << "-500 - 500 = " << (c - d) << " (期望 -1000)" << endl;
    
    // 负 - 负（相当于比绝对值，如 -500 - (-1000) = 500）
    BigInt e("-1000");
    cout << "-500 - -1000 = " << (c - e) << " (期望 500)" << endl;
    cout << "-1000 - -500 = " << (e - c) << " (期望 -500)" << endl;


    cout << "\n=== 测试 2: 连续借位地狱 ===" << endl;
    // 跨多个 0 的借位（极其容易写错）
    BigInt big("100000000000");
    BigInt small("1");
    cout << "100000000000 - 1 = " << (big - small) << " (期望 99999999999)" << endl;
    
    BigInt big2("100000");
    BigInt small2("99999");
    cout << "100000 - 99999 = " << (big2 - small2) << " (期望 1)" << endl;
    
    // 长度跨越极大的借位
    BigInt huge("100000000000000000000");
    BigInt tiny("99999999999999999999");
    cout << "10^20 - (10^20-1) = " << (huge - tiny) << " (期望 1)" << endl;


    cout << "\n=== 测试 3: 零的终极试探 ===" << endl;
    BigInt zero("0");
    
    // 任何数减自己，必须彻底归零，绝不能带符号
    cout << "888888 - 888888 = " << (BigInt("888888") - BigInt("888888")) << " (期望 0)" << endl;
    cout << "-55555 - -55555 = " << (BigInt("-55555") - BigInt("-55555")) << " (期望 0)" << endl;
    
    // 0 减别人
    cout << "0 - 12345 = " << (zero - BigInt("12345")) << " (期望 -12345)" << endl;
    cout << "0 - -12345 = " << (zero - BigInt("-12345")) << " (期望 12345)" << endl;
    
    // 别人减 0
    cout << "12345 - 0 = " << (BigInt("12345") - zero) << " (期望 12345)" << endl;
    cout << "-12345 - 0 = " << (BigInt("-12345") - zero) << " (期望 -12345)" << endl;


    cout << "\n=== 测试 4: 复合减法 (-=) 测试 ===" << endl;
    BigInt comp("1000");
    comp -= BigInt("200");
    cout << "1000 -= 200 -> " << comp << " (期望 800)" << endl;
    
    comp -= BigInt("800");
    cout << "800 -= 800  -> " << comp << " (期望 0)" << endl;
    
    comp -= BigInt("1");
    cout << "0 -= 1      -> " << comp << " (期望 -1)" << endl;

    // 测试连续调用和返回值（如果返回引用的话）
    BigInt comp2("100");
    (comp2 -= BigInt("50")) -= BigInt("20");
    cout << "100 -= 50 -= 20 -> " << comp2 << " (期望 30)" << endl;


    cout << "\n=== 测试 5: 减法与深拷贝 ===" << endl;
    BigInt src("9999");
    BigInt dst = src - BigInt("1111");
    cout << "9999 - 1111 = " << dst << " (期望 8888)" << endl;

    // 自身减法赋值（a = a - b）
    BigInt self("500");
    self = self - BigInt("300");
    cout << "500 = 500 - 300 -> " << self << " (期望 200)" << endl;

    return 0;
}
