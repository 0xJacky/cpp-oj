//
//  main.cpp
//  表达式求值
//
//  Created by Jacky on 2020/9/9.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 表达式求值
 题目描述
 对以下表达式进行求值，a、b、c是三个变量，它们都是小于100的自然数
 a+b>c&&b==c
 
 输入
 第一行输入T，表示后续有T个测试示例
 第二行开始，每行输入3个变量值，输入T行
 输出
 每行输出计算结果
 样例输入
 3
 5 6 7
 4 5 5
 6 1 9
 样例输出
 0
 1
 0
 */

#include <iostream>
using namespace std;

int main() {
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << (a + b > c && b == c) << endl;
    }
    return 0;
}