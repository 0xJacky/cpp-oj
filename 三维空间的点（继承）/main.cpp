//
//  main.cpp
//  三维空间的点（继承）
//
//  Created by Jacky on 2020/11/17.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义一个平面上的点C2D类，它含有一个getDistance()的成员函数，计算该点到原点的距离；从C2D类派生出三维空间的点C3D类，它的getDistance()成员函数计算该点到原点的距离。试分别生成一个C2D和C3D的对象，计算它们到原点的距离。
 三维空间的两点（x, y, z）和（x1, y1, z1）的距离公式如下：
 [(x-x1)2+(y-y1)2+(z-z1)2](1/2)
 输入
 第一行二维坐标点位置
 
 第二行三维坐标点位置1
 
 第三行三维坐标点位置2
 
 输出
 第一行二维坐标点位置到原点的距离
 
 第二行三维坐标点位置1到原点的距离
 
 第三行三维坐标点位置2到原点的距离
 
 第四行三维坐标点位置2赋值给二维坐标点变量后，二维坐标点到原点的距离
 
 样例输入
 3 4
 3 4 5
 6 8 8
 样例输出
 5
 7.07107
 12.8062
 10
 */

#include <cmath>
#include <iostream>
using namespace std;

class C2D {
public:
    double x, y;
    C2D();
    C2D(double _x, double _y) : x(_x), y(_y) {}
    void getDistance() {
        cout << sqrt(x * x + y * y) << endl;
    }
};

class C3D : public C2D {
public:
    double z;
    C3D();
    C3D(double _x, double _y, double _z) : C2D(_x, _y), z(_z) {}
    void getDistance() {
        cout << sqrt(x * x + y * y + z * z) << endl;
    }
};

int main() {
    double x, y, z;
    cin >> x >> y;
    C2D c1(x, y);
    c1.getDistance();
    cin >> x >> y >> z;
    C3D c2(x, y, z);
    c2.getDistance();
    cin >> x >> y >> z;
    C3D c3(x, y, z);
    c3.getDistance();
    c3.C2D::getDistance();
    return 0;
}