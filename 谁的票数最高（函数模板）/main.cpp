//
//  main.cpp
//  谁的票数最高（函数模板）
//
//  Created by Jacky on 2020/12/22.
//  Copyright © 2020 Jacky. All rights reserved.
//
/*
 题目描述
 某小镇要票选镇长，得票最高者当选。但由于投票机制不健全，导致每届投票时，候选人在投票系统的识别码类型不一致。请编写函数模板，能针对多种类型的数据，查找出得票最高的元素。其中，每届投票的选票有n张，识别码类型为T

 注意：必须使用模板函数

 输入
 第一行输入t表示有t个测试实例

 第二行先输入一个大写字母表示识别码类型，I表示整数类型，C表示字符型，S表示字符串型；然后输入n表示数组长度。

 第三行输入n个数据

 依次输入t个实例

 输出
 每行输出一个结果，分别输出当选者的识别码和得票数，以空格分开。

 样例输入
 3
 I 10
 5 3 5 2 9 7 3 7 2 3
 C 8
 a b a e b e e q
 S 5
 sandy david eason cindy cindy
 样例输出
 3 3
 e 3
 cindy 2
 提示
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

template <typename T>
void test(T t, int length) {
    map<T, int> buffer;
    int max = 0;
    T p = t;
    for (int i = 0; i < length; i++) {
        T tmp;
        cin >> tmp;
        if (++buffer[tmp] > max) {
            max = buffer[tmp];
            p = tmp;
        }
    }
    cout << p << " "<< max << endl;
}

int main() {
    int t, length;
    char type;
    cin >> t;
    while (t--) {
        cin >> type >> length;
        if (type == 'I') {
            int p = 0;
            test(p, length);
        } else if (type == 'C') {
            char p = 'A';
            test(p, length);
        } else if (type == 'S') {
            string p = "";
            test(p, length);
        }
    }
    return 0;
}
