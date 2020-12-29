//
//  main.cpp
//  数据排序（函数模板）
//
//  Created by Jacky on 2020/12/22.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 编写一个进行升序排序的函数模板，其中数组为具有n个元素，类型为T。

 注意：必须使用模板函数

 输入
 第一行输入t表示有t个测试实例

 第二行先输入一个大写字母表示数组类型，I表示整数类型，C表示字符型，S表示字符串型，D表示双精度数类型；然后输入n表示数组长度。

 第三行输入n个数据

 依次输入t个实例

 输出
 每行输出一个结果

 样例输入
 4
 I 10
 15 3 51 27 9 35 78 14 65 8
 D 3
 -11.3 25.42 13.2
 C 6
 a b g e u q
 S 4
 sandy david eason cindy
 样例输出
 3 8 9 14 15 27 35 51 65 78
 -11.3 13.2 25.42
 a b e g q u
 cindy david eason sandy
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
        cout << a[i] << " ";
    }
    cout << endl;
}
template <typename T>
void test(T a[], int length) {
    getInput(a, length);
    mySort(a, length);
    display(a, length);
}

int main() {
    int t, length;
    char type;
    cin >> t;
    while (t--) {
        cin >> type >> length;
        if (type == 'I') {
            int a[length];
            test(a, length);
        } else if (type == 'C') {
            char a[length];
            test(a, length);
        } else if (type == 'S') {
            string a[length];
            test(a, length);
        } else if (type == 'D') {
            double a[length];
            test(a, length);
        }
    }
    return 0;
}
