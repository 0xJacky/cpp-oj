//
//  main.cpp
//  三数论大小（指针）
//
//  Created by Jacky on 2020/9/24.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 输入三个整数，然后按照从大到小的顺序输出数值。
 要求：用三个指针分别指向这三个整数，排序过程必须通过这三个指针来操作，不能直接访问这三个整数
 输出时，必须使用这三个指针，不能使用存储三个整数的变量
 
 输入
 第一行输入t表示有t个测试实例
 第二行起，每行输入三个整数
 输入t行
 
 输出
 每行按照从大到小的顺序输出每个实例
 在每行中，每个数据输出后都带有一个空格，即使该行最后一个数据输出后也要再输出一个空格
 
 样例输入
 3
 2 4 6
 88 99 77
 111 333 222
 样例输出
 6 4 2
 99 88 77
 333 222 111 */

#include <iostream>
using namespace std;

void _f(int *x, int *y) {
    if (*x < *y) {
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    }
}

int main() {
    int n, f, s, t;
    int *x = &f, *y = &s, *z = &t;
    cin >> n;

    while (n--) {
        cin >> f >> s >> t;

        _f(x, y);
        _f(x, z);
        _f(y, z);

        cout << *x << " " << *y << " " << *z << " " << endl;
    }
    return 0;
}