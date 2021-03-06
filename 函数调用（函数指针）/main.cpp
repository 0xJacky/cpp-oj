//
//  main.cpp
//  函数调用（函数指针）
//
//  Created by Jacky on 2020/9/27.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义并实现三个函数：
 第一个函数是整数函数，返回类型为整数，参数是一个整数变量，操作是求该变量的平方值
 第二个函数是浮点数函数，返回类型为浮点数，参数是一个浮点数变量，操作是求该变量的平方根值。求平方根可以使用函数sqrt（浮点参数），将返回该参数的平方根，在VC中需要头文件cmath。
 第三个函数是字符串函数，无返回值，参数是一个字符串指针，操作是把这个字符串内所有小写字母变成大写。
 要求：定义三个函数指针分别指向这三个函数，然后根据调用类型使用函数指针来调用这三个函数。不能直接调用这三个函数。
 如果类型为I，则通过指针调用整数函数；如果类型为F，则通过指针调用浮点数函数；如果类型为S，则通过指针调用字符串函数
 
 输入
 第一行输入一个t表示有t个测试实例
 每行先输入一个大写字母，表示调用类型，然后再输入相应的参数
 依次输入t行
 
 输出
 每行输出调用函数后的结果
 
 样例输入
5
S shenzhen
I 25
F 6.25
I 31
S China
 样例输出
 SHENZHEN
 625
 2.5
 961
 CHINA
 */

#define N 1000
#include <cmath>
#include <iostream>

using namespace std;

int sq(int n) {
    return n * n;
}

float _sqrt(float n) {
    return sqrt(n);
}

void capital(char *p) {
    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p -= 32;
        }
        p++;
    }
}

int main() {
    int t, a, (*I)(int) = sq;
    float b, (*F)(float) = _sqrt;
    char type, input[N];
    void (*S)(char *) = capital;
    cin >> t;
    while (t--) {
        cin >> type;
        switch (type) {
            case 'S':
                cin >> input;
                (*S)(input);
                cout << input;
                break;
            case 'I':
                cin >> a;
                cout << (*I)(a);
                break;
            case 'F':
                cin >> b;
                cout << (*F)(b);
                break;
        }
        cout << endl;
    }
    return 0;
}