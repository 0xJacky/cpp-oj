//
//  main.cpp
//  复数运算（友元函数）
//
//  Created by Jacky on 2020/11/3.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 复数运算（友元函数）
 题目描述
 复数类的声明如下：
 
 class Complex {
 public:
 Complex();
 Complex(double r, double i);
 friend Complex addCom(Complex c1, Complex c2);
 friend Complex minusCom(Complex c1, Complex c2);
 friend void outCom(Complex c);
 private:
 double real; //实部
 double imag; //虚部
 };
 
 要求如下：
 1.     实现复数类和友元函数addCom和outCom。
 2.   参考addCom函数为复数类增加一个友元函数minusCom，用于实现两个复数的减法
 3.     在main函数中，通过友元函数，实现复数的加减法和复数的输出。
 
 输入
 第1行：第1个复数的实部和虚部
 
 第2行：需进行运算的次数，注意：是连续运算。具体结果可参考样例
 
 第3行开始，每行输入运算类型，以及参与运算的复数的实部与虚部。“+”表示复数相加，“-”表示复数相减。
 
 输出
 每行输出复数运算后的结果，复数输出格式为“(实部,虚部)”。
 
 样例输入
 10 10
 3
 + 20 10
 - 15 5
 + 5 25
 样例输出
 (30,20)
 (15,15)
 (20,40)
 */

#include <iostream>
using namespace std;

class Complex {
public:
    Complex();
    Complex(double r, double i);
    friend Complex addCom(Complex c1, Complex c2);
    friend Complex minusCom(Complex c1, Complex c2);
    friend void outCom(Complex c);

private:
    double real;  //实部
    double imag;  //虚部
};

Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex addCom(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex minusCom(Complex c1, Complex c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

void outCom(Complex c) {
    cout << "(" << c.real << "," << c.imag << ")" << endl;
}

int main() {
    char opt;
    double r, i;
    int t;
    cin >> r >> i >> t;
    Complex base(r, i);
    while (t--) {
        cin >> opt >> r >> i;
        Complex c(r, i);
        if (opt == '+') {
            base = addCom(base, c);
        } else {
            base = minusCom(base, c);
        }
        outCom(base);
    }
    return 0;
}