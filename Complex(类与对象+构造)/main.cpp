//
//  main.cpp
//  Complex(类与对象+构造)
//
//  Created by Jacky on 2020/10/19.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 编写一个复数类，能实现加、减运算，能输出复数的信息。 要求至少包含以下方法：
 1、缺省（无参）构造函数，设置实部与虚部为1；
 2、有参构造函数，给实部与虚部赋值；
 3、加法运算，计算两个复数的和；
 4、减法运算，计算两个复数的差；
 5、输出方法，输出当前复数的值
 输入
 测试数据的组数t 第一组的两个复数的实部 虚部 实部 虚部 第二组的两个复数的实部 虚部 实部 虚部 ......
 输出
 第一组两个复数的和 第一组两个复数的差
 样例输入
 4
 2 1 2 1
 2 1 2 -1
 3 1 2 -6
 3 3 2 2
 样例输出
 sum:4+2i
 remainder:0
 sum:4
 remainder:2i
 sum:5-5i
 remainder:1+7i
 sum:5+5i
 remainder:1+i
 提示
 */

#include <iostream>
using namespace std;

class Complex {
protected:
    int r, v;

public:
    Complex(int _r = 0, int _v = 0) : r(_r), v(_v) {}
    Complex operator+(Complex& c) {
        Complex ans(r + c.r, v + c.v);
        return ans;
    }
    Complex operator-(Complex& c) {
        Complex ans(r - c.r, v - c.v);
        return ans;
    }
    friend ostream& operator<<(ostream& cout, Complex& c);
};

ostream& operator<<(ostream& cout, Complex& c) {
    if (c.r == 0 && c.v == 0) {
        cout << "0";
        goto print_end;
    }

    if (c.r == 0 && c.v != 0) {
        goto print_v;
    }

    cout << c.r;

    if (c.v == 0) {
        goto print_end;
    }

    if (c.v > 0) {
        cout << "+";
    }
print_v:
    if (c.v == 1 || c.v == -1) {
        cout << "i";
    } else {
        cout << c.v << "i";
    }

print_end:
    return cout;
}

int main() {
    int t, r1, v1, r2, v2;
    cin >> t;
    while (t--) {
        cin >> r1 >> v1 >> r2 >> v2;
        Complex c1(r1, v1), c2(r2, v2);
        Complex sum = c1 + c2, remainder = c1 - c2;

        cout << "sum:" << sum << endl;
        cout << "remainder:" << remainder << endl;
    }
    return 0;
}