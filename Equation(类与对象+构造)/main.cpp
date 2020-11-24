//
//  main.cpp
//  Equation(类与对象+构造)
//
//  Created by Jacky on 2020/10/18.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 建立一个类Equation，表达方程ax2+bx+c=0。类中至少包含以下方法：
 1、无参构造（abc默认值为1、1、0）与有参构造函数，用于初始化a、b、c的值；
 2、set方法，用于修改a、b、c的值
 3、getRoot方法，求出方程的根。
 
 输入
 输入测试数据的组数t
 第一组a、b、c
 第二组a、b、c
 输出
 输出方程的根，结果到小数点后2位
 在C++中，输出指定精度的参考代码如下：
 
 #include <iostream>
 #include <iomanip> //必须包含这个头文件
 using namespace std;
 void main( )
 { double a =3.141596;
 cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位
 ｝
 
 样例输入
 3
 2 4 2
 2 2 2
 2 8 2
 样例输出
 x1=x2=-1.00
 x1=-0.50+0.87i x2=-0.50-0.87i
 x1=-0.27 x2=-3.73
 提示
 */
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

class Equation {
    double a, b, c;
public:
    Equation() {
        set(1, 1, 0);
    }
    Equation(double a, double b, double c) {
        set(a, b, c);
    }
    void set(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void getRoot() {
        double delta = b * b - 4 * a * c;
        double s_delta = sqrt(fabs(delta));
        cout << fixed << setprecision(2);
        if (delta > 0) {
            cout << "x1=" << (-b + s_delta) / (2 * a) << " x2=" << (-b - s_delta) / (2 * a);
        }
        else if (delta < 0) {
            cout << "x1=" << -b / (2 * a) << "+" << s_delta / (2 * a) << "i x2=" << -b / (2 * a) << "-" << s_delta / (2 * a) << "i";
        }
        else {
            cout << "x1=x2=" << (-b + s_delta) / (2 * a);
        }
        cout << endl;
    }
};

int main()
{
    int t;
    double a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        Equation equation(a, b, c);
        equation.getRoot();
    }
    return 0;
}
