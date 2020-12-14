//
//  main.cpp
//  Point（类与构造）
//
//  Created by Jacky on 2020/10/18.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 下面是一个平面上的点的类定义，请在类外实现它的所有方法，并生成点测试它。
 
 
 输入
 测试数据的组数 t
 第一组测试数据点p1的x坐标   第一组测试数据点p1的y坐标  第一组测试数据点p2的x坐标   第一组测试数据点p2的y坐标
 ..........
 输出
 输出p1到p2的距离
 在C++中，输出指定精度的参考代码如下：
 
 #include <iomanip> //必须包含这个头文件
 #include <iostream>
 using namespace std;
 void main( )
 { double a =3.141596;
 cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位
 }
 
 
 样例输入
 2
 1 2 3 4
 -1 0.5 -2 5
 样例输出
 Distance of Point(1.00,2.00) to Point(3.00,4.00) is 2.83
 Distance of Point(-1.00,0.50) to Point(-2.00,5.00) is 4.61
 提示
 */

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Point {
    double x, y;

public:
    Point();
    Point(double x_value, double y_value);

    double getX();
    double getY();
    void setX(double x_value);
    void setY(double y_value);
    double distanceToAnotherPoint(Point p);
};

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x_value, double y_value) {
    this->setX(x_value);
    this->setY(y_value);
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

void Point::setX(double x_value) {
    this->x = x_value;
}

void Point::setY(double y_value) {
    this->y = y_value;
}

double Point::distanceToAnotherPoint(Point p) {
    return sqrt((this->getX() - p.x) * (this->getX() - p.x) +
                (this->getY() - p.y) * (this->getY() - p.y));
}

int main() {
    int t;
    double x1, y1, x2, y2, ans;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1), p2(x2, y2);
        ans = p1.distanceToAnotherPoint(p2);
        cout << fixed << setprecision(2) << "Distance of Point(" << x1 << ","
             << y1 << ") to Point(" << x2 << "," << y2 << ") is " << ans
             << endl;
    }
    return 0;
}