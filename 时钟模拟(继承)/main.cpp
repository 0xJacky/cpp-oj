//
//  main.cpp
//  时钟模拟(继承)
//
//  Created by Jacky on 2020/11/24.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义计数器类，包含保护数据成员value,公有函数increment计数加1。

 定义循环计算器继承计数器类，增加私有数据成员：最小值min_value，最大值max_value,

 重写公有函数increment，使得value在min_value~max_value区间内循环+1。

 定义时钟类，数据成员是私有循环计数器对象小时hour、分钟minute、秒second，公有函数time(int s)计算当前时间经过s秒之后的时间，即hour,minute,second的新value值。

 定义时钟类对象，输入当前时间和经过的秒数,调用time函数计算新时间。

 根据题目要求，增加必要的构造函数、析构函数和其他所需函数。

 因为clock是系统内置函数，为了避免重名，请不要使用clock作为类名或者函数名

 输入
 第一行测试次数n

 2行一组，第一行为当前时间（小时 分钟 秒），第二行为经过的秒数。

 输出
 输出n行

 每行对应每组当前时间和经过秒数后计算得到的新时间（小时：分钟：秒）。

 样例输入
 2
 8 19 20
 20
 23 30 0
 1801
 样例输出
 8:19:40
 0:0:1
 */

#include <iostream>
using namespace std;

class Counter {
protected:
    int value;

public:
    Counter(int v) : value(v) {}
    void increment() {
        value++;
    }
    int getValue() {
        return value;
    }
};

class CircleCounter : public Counter {
private:
    int min_value;
    int max_value;

public:
    CircleCounter(int min, int v, int max)
        : Counter(v), min_value(min), max_value(max) {}
    void increment() {
        if (value == max_value) {
            value = min_value;
        } else {
            value++;
        }
    }
};

class Timer {
private:
    CircleCounter hour;
    CircleCounter minute;
    CircleCounter second;

public:
    Timer(int h, int m, int s)
        : hour(0, h, 23), minute(0, m, 59), second(0, s, 59) {}
    void time(int s) {
        auto _s = s % 60;
        auto m = (s / 60) % 60;
        if (_s + second.getValue() >= 60) {
            m++;
        }
        auto h = ((s / 60) / 60) % 24;
        if (m + minute.getValue() >= 60) {
            h++;
        }
        for (int i = 0; i < _s; i++) {
            second.increment();
        }
        for (int i = 0; i < m; i++) {
            minute.increment();
        }
        for (int i = 0; i < h; i++) {
            hour.increment();
        }
    }
    void display() {
        cout << hour.getValue() << ":" << minute.getValue() << ":"
             << second.getValue() << endl;
    }
};

int main() {
    int t, h, m, s, p;
    cin >> t;
    while (t--) {
        cin >> h >> m >> s >> p;
        Timer timer(h, m, s);
        timer.time(p);
        timer.display();
    }
    return 0;
}