//
//  main.cpp
//  时钟调整（运算符前后增量）
//
//  Created by Jacky on 2020/12/14.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 假定一个时钟包含时、分、秒三个属性，取值范围分别为0~ 11，0~ 59，0~59，
 具体要求如下：

 1、用一元运算符++，并且是前增量的方法，实现时钟的调快操作。例如要把时钟调快5秒，则执行5次” ++<对象> “ 的操作

 2、用一元运算符--，并且是后增量的方法，实现时钟的调慢操作。例如要把时钟调慢10秒，则执行10次” <对象>-- “的操作

 3、用构造函数的方法实现时钟对象的初始化，用输出函数实现时钟信息的输出

 clock和time是系统内部函数，所以不要用来做类名或者其它

 输入
 第一行输入时钟的当前时间时、分、秒

 第二行输入t表示有t个示例

 第三行输入t个整数x，如果x为正整数，则表示执行调快操作，使用重载运算符++；如果x为负整数，则表示执行调慢操作，使用重载运算符–

 每次的调快或调慢操作都是承接上一次调整后的结果进行，例如先调快10秒，再调慢2秒，那么调慢2秒是接着调快10秒后的结果进行的

 输出
 每行输出每个时钟调整操作后的时分秒

 样例输入
 11 58 46
 4
 5 70 -22 -55
 样例输出
 11:58:51
 0:0:1
 11:59:39
 11:58:44
 */

#include <iostream>
using namespace std;

class Timer {
    int h, m, s;

public:
    Timer(int _h, int _m, int _s) : h(_h), m(_m), s(_s) {}
    Timer operator++() {
        ++s;
        if (s > 59) {
            s %= 60;
            m++;
        }
        if (m > 59) {
            h++;
            m %= 60;
        }
        if (h > 11) {
            h %= 12;
        }
        return Timer(h, m, s);
    }
    Timer operator--(int) {
        s--;
        if (s < 0) {
            s = 60 + s;
            m--;
        }
        if (m < 0) {
            h--;
            m = 60 + m;
        }
        if (h < 0) {
            h = 12 + h;
        }
        return Timer(h, m, s);
    }
    friend ostream &operator<<(ostream &cout, Timer &t);
};

ostream &operator<<(ostream &cout, Timer &t) {
    cout << t.h << ":" << t.m << ":" << t.s;
    return cout;
}

int main() {
    int h, m, s, t;
    cin >> h >> m >> s >> t;
    Timer c(h, m, s);
    while (t--) {
        cin >> s;
        if (s > 0) {
            for (int i = 0; i < s; i++) {
                ++c;
            }
        } else {
            for (int i = 0; i < -s; i++) {
                c--;
            }
        }
        cout << c << endl;
    }
    return 0;
}
