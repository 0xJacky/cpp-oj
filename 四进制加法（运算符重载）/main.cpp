//
//  main.cpp
//  四进制加法（运算符重载）
//
//  Created by Jacky on 2020/12/8.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义一个四进制的类，重定义“+”号实现四进制数的累加。

 输入
 第一行输入所需要的四进制数的个数
 第二行开始，依次输入四进制数
 输出
 所有输入四进制数累加的和

 样例输入
 3
 13
 2
 21
 样例输出
 102
 提示
 */

#define N 16
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class QuaternaryInt {
    string value;
public:
    QuaternaryInt(string v = "0"): value(v) {
        while (value.length() < N) {
            value = "0" +  value;
        }
    }
    
    QuaternaryInt operator+(QuaternaryInt &a) {
        string v, tmp;
        stringstream ss;
        int next = 0, current = 0;
        for (int i = N - 1; i >= 0; i--) {
            current = value[i] + a.value[i] - 2 * '0' + next;
            if (current > 3) {
                next = current / 4;
                current %= 4;
            } else {
                next = 0;
            }
            ss.clear();
            ss << current;
            ss >> tmp;
            v = tmp + v;
        }
        return QuaternaryInt(v);
    }
    
    friend ostream& operator<<(ostream& cout, QuaternaryInt &a);
};

ostream & operator<<(ostream& cout, QuaternaryInt &a) {
    int i;
    for (i = 0; i < N - 1; i++) {
        if(a.value[i]!='0')break;
    }
    return cout << a.value.substr(i, N);
}

int main() {
    int t;
    cin >> t;
    QuaternaryInt a;
    while (t--) {
        string v;
        cin >> v;
        QuaternaryInt b(v);
        a = a + b;
    }
    cout << a << endl;
    return 0;
}
