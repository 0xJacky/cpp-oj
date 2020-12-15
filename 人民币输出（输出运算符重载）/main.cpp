//
//  main.cpp
//  人民币输出（输出运算符重载）
//
//  Created by Jacky on 2020/12/14.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义一个人民币类，包括元、角、分三个非负整数属性，操作包括初始化和输出

 初始化用构造函数实现，接收一个浮点数参数（精度为小数点后两位），并转化为元、角、分，例如输入1.23元，经过构造函数转为1元、2角、3分

 输出函数对元角分进行输出，具体格式看示例

 由于OJ编译器对double强制类型转换成int的处理精度有偏差，建议加0.5处理(例如数据1.38，由于误差，在内存中的存储值为1.379999）

 可以用全局函数重载法（课本介绍的），或者友元方法，两种方法来尝试实现

 输入
 第一行输入t表示有t个实例

 第二行起，输入t个正浮点数，带两位小数，每个数值表示以元为单位的人民币金额

 输出
 每行输出把浮点数的人民币金额，转化为元角分的整数格式，具体看输出

 样例输入
 2
 2.45
 1.38
 样例输出
 yuan=2 jiao=4 fen=5
 yuan=1 jiao=3 fen=8
 */

#include <iostream>
#include <sstream>
using namespace std;

class RMB {
    int y, j, f;

public:
    RMB(int _y, int _j, int _f) : y(_y), j(_j), f(_f) {}
    friend ostream& operator<<(ostream& cout, RMB& r);
};

ostream& operator<<(ostream& cout, RMB& r) {
    cout << "yuan=" << r.y << " jiao=" << r.j << " fen=" << r.f;
    return cout;
}

int main() {
    int t, y, j, f;
    string money;
    stringstream ss;
    cin >> t;
    while (t--) {
        ss.clear();
        cin >> money;
        int point;
        for (point = 0; point < money.size(); point++) {
            if (money[point] == '.') break;
        }
        ss << money.substr(0, point);
        ss >> y;
        ss.clear();
        ss << money[point + 1];
        ss >> j;
        ss.clear();
        ss << money[point + 2];
        ss >> f;
        RMB rmb(y, j, f);
        cout << rmb << endl;
    }
    return 0;
}
