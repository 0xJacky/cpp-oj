//
//  main.cpp
//  图形面积（虚函数与多态）
//
//  Created by Jacky on 2020/11/30.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 编写一个程序，定义抽象基类Shape，在Shape类中定义虚函数Area()；由它派生出3个派生类：Circle(圆形)、Square(正方形)、Rectangle(矩形)。用虚函数分别计算几种图形面积。
 1、要求输出结果保留两位小数。
 2、要求用基类指针数组，使它每一个元素指向每一个派生类对象。
 输入
 测试数据的组数 t

 第一组测试数据中圆的半径

 第一组测测试数据中正方形的边长

 第一组测试数据中矩形的长、宽

 .......

 第 t 组测试数据中圆的半径

 第 t 组测测试数据中正方形的边长

 第 t 组测试数据中矩形的长、宽

 输出
 第一组数据中圆的面积

 第一组数据中正方形的面积

 第一组数据中矩形的面积

 ......

 第 t 组数据中圆的面积

 第 t 组数据中正方形的面积

 第 t 组数据中矩形的面积

 样例输入
 2
 1.2
 2.3
 1.2 2.3
 2.1
 3.2
 1.23 2.12
 样例输出
 4.52
 5.29
 2.76
 13.85
 10.24
 2.61
 提示
 */

#define PI 3.1415
#include <iostream>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual float Area() = 0;
};

class Circle : public Shape {
public:
    float r;
    Circle(float _r) : r(_r) {}
    float Area() {
        return r * r * PI;
    }
};

class Square : public Shape {
public:
    float r;
    Square(float _r) : r(_r) {}
    float Area() {
        return r * r;
    }
};

class Rectangle : public Shape {
public:
    float x, y;
    Rectangle(float _x, float  _y) : x(_x), y(_y) {}
    float Area() {
        return x * y;
    }
};

void print_area(Shape * s) {
    cout << fixed << setprecision(2) << s->Area() << endl;
}

int main() {
    int t;
    float x, y;
    cin >> t;
    while (t--) {
        Shape **p = new Shape * [3];
        cin >> x;
        p[0] = new Circle(x);
        print_area(p[0]);
        cin >> x;
        p[1] = new Square(x);
        print_area(p[1]);
        cin >> x >> y;
        p[2] = new Rectangle(x, y);
        print_area(p[2]);
        delete [] p;
    }
    return 0;
}
