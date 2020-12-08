//
//  main.cpp
//  表面积计算
//
//  Created by Jacky on 2020/9/10.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 表面积计算（不含答案）
 题目描述
 给出一个立方体的长宽高，计算它的表面积
 
 输入
 第一行输入参数T，表示有T个测试实例
 第二行输入一个立方体的长宽高，长宽高均为小于100的正整数
 以此类推
 
 输出
 输出每个立方体的表面积
 
 样例输入
 2
 1 2 3
 4 5 6
 样例输出
 22
 148
 */
#include <iostream>
using namespace std;

int main() {
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << ((a * b + b * c + a * c) * 2) << endl;
    }

    return 0;
}