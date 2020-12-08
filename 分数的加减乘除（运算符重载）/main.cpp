//
//  main.cpp
//  分数的加减乘除（运算符重载）
//
//  Created by Jacky on 2020/12/7.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 Fraction类的基本形式如下：
 ```
 class Fraction {
 int numerator, denominator;
 int common_divisor();
 void contracted();
 public:
 Fraction(int=0; int=1);
 Fraction(Fraction&);
 Fraction operator+(Fraction);
 Fraction operator-(Fraction);
 Fraction operator*(Fraction);
 Fraction operator/(Fraction);
 void Set(int=0,int=1);
 void disp() {cout << "fraction=" << numerator << "/" << denominator << endl;}
 };
 ```
 要求如下：
 1.实现Fraction类；common_divisor()和contracted()函数体可为空，不实现具体功能。
 2.编写main函数，初始化两个Fraction对象的，计算它们之间的加减乘除。
 输入
 第1行：依次输入第1个和第2个Fraction对象的分子和分母值。

 输出
 每行依次分别输出加减乘除计算后的Fraction对象（直接输出分数值，不需要约简）。

 样例输入
 1 3 2 5
 样例输出
 fraction=11/15
 fraction=-1/15
 fraction=2/15
 fraction=5/6
 提示
 */

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;
    int common_divisor();
    void contracted();
public:
    Fraction(int n = 0, int d = 1): numerator(n), denominator(d) {}
    //Fraction(Fraction&);
    Fraction operator+(const Fraction & f) {
        auto n = numerator * f.denominator + f.numerator * denominator;
        auto d = denominator * f.denominator;
        return Fraction(n, d);
    }
    Fraction operator-(const Fraction & f) {
        auto n = numerator * f.denominator - f.numerator * denominator;
        auto d = denominator * f.denominator;
        return Fraction(n, d);
    }
    Fraction operator*(const Fraction & f) {
        auto n = numerator * f.numerator;
        auto d = denominator * f.denominator;
        return Fraction(n, d);
    }
    Fraction operator/(const Fraction & f) {
        auto n = numerator * f.denominator;
        auto d = denominator * f.numerator;
        return Fraction(n, d);
    }
    void Set(int n = 0,int d = 1) {
        this->numerator = n;
        this->denominator = d;
    }
    void display() {
        cout << "fraction=" << numerator << "/" << denominator << endl;
    }
};


int main() {
    int n, d;
    cin >> n >> d;
    Fraction a(n, d);
    cin >> n >> d;
    Fraction b(n, d);
    (a+b).display();
    (a-b).display();
    (a*b).display();
    (a/b).display();
    return 0;
}
