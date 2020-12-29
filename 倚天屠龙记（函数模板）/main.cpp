//
//  main.cpp
//  倚天屠龙记（函数模板）
//
//  Created by Jacky on 2020/12/22.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 江湖中有一个传言，只要倚天剑和屠龙刀中暗藏的秘密拼到一起，就能得到天下无敌的内功秘笈。设计一个函数模板，完成拼凑的功能（将倚天剑的秘密连接到屠龙刀的后面），并将秘笈输出. 其中每个秘密由n个元素组成，类型为T。

 输入
 第一行输入t表示有t个测试实例

 第二行先输入一个大写字母表示数据类型，I表示整数类型，D表示双精度数类型，C表示字符型；然后输入n表示数据个数。

 第三行输入倚天剑的n个数据

 第四行输入屠龙刀的n个数据

 依次输入t个实例

 输出
 每行输出一个结果

 样例输入
 2
 I 5
 5 3 51 27 9
 27 0 0 5 1
 C 5
 kitty
 hello
 样例输出
 2700515351279
 hellokitty
 提示
 */

#include <iostream>
#include <string>
using namespace std;

template <typename T>
void mySort(T a[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                T tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

template <typename T>
void getInput(T a[], int length) {
    for (int i = 0; i < length; i++) {
        cin >> a[i];
    }
}

template <typename T>
void display(T a[], int length) {
    for (int i = 0; i < length; i++) {
        cout << a[i];
    }
}

template <typename T>
void test(T a[], T b[], int length) {
    getInput(a, length);
    getInput(b, length);
    display(b, length);
    display(a, length);
    cout << endl;
}

int main() {
    int t, length;
    char type;
    cin >> t;
    while (t--) {
        cin >> type >> length;
        if (type == 'I') {
            int a[length], b[length];
            test(a, b, length);
        } else if (type == 'C') {
            char a[length], b[length];
            test(a, b, length);
        } else if (type == 'S') {
            string a[length], b[length];
            test(a, b, length);
        } else if (type == 'D') {
            double a[length], b[length];
            test(a, b, length);
        }
    }
    return 0;
}
