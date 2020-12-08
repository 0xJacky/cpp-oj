//
//  main.cpp
//  分数类（类与构造）
//
//  Created by Jacky on 2020/10/18.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 完成下列分数类的实现:
 class CFraction
 {
 private:
    int fz, fm;
 public:
    CFraction(int fz_val, int fm_val) ;
    CFraction add(const CFraction &r);
    CFraction sub(const CFraction &r);
    CFraction mul(const CFraction &r);
    CFraction div(const CFraction &r);
    int getGCD();   // 求对象的分子和分母的最大公约数
    void print();
 };
 求两数a、b的最大公约数可采用辗转相除法，又称欧几里得算法，其步骤为:
 1. 交换a, b使a > b;
 2. 用a除b得到余数r,若r=0,则b为最大公约数,退出.
 3. 若r不为0,则用b代替a, r代替b,此时a,b都比上一次的小,问题规模缩小了;
 4. 继续第2步。
 输入
 测试数据的组数 t
 第一组第一个分数
 第一组第二个分数
 第二组第一个分数
 第二组第二个分数
 ......
 输出
 第一组两个分数的和
 第一组两个分数的差
 第一组两个分数的积
 第一组两个分数的商
 第二组两个分数的和
 第二组两个分数的差
 第二组两个分数的积
 第二组两个分数的商
 ......
 样例输入
 3
 1/2
 2/3
 3/4
 5/8
 21/23
 8/13
 样例输出
 7/6
 -1/6
 1/3
 3/4
 
 11/8
 1/8
 15/32
 6/5
 
 457/299
 89/299
 168/299
 273/184
 
 提示
 */

#include <iostream>
using namespace std;

class CFraction {
private:
    int fz, fm;

public:
    CFraction(int fz_val, int fm_val);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    int getGCD();  // 求对象的分子和分母的最大公约数
    void print();
};

CFraction::CFraction(int fz_val, int fm_val) {
    this->fz = fz_val;
    this->fm = fm_val;
};

CFraction CFraction::add(const CFraction& r) {
    auto _fz = fz * r.fm + r.fz * fm;
    auto _fm = fm * r.fm;
    return CFraction(_fz, _fm);
}

CFraction CFraction::sub(const CFraction& r) {
    auto _fz = fz * r.fm - r.fz * fm;
    auto _fm = fm * r.fm;
    return CFraction(_fz, _fm);
}

CFraction CFraction::mul(const CFraction& r) {
    auto _fz = fz * r.fz;
    auto _fm = fm * r.fm;
    return CFraction(_fz, _fm);
}

CFraction CFraction::div(const CFraction& r) {
    auto _fz = fz * r.fm;
    auto _fm = fm * r.fz;
    return CFraction(_fz, _fm);
}

int CFraction::getGCD() {
    auto a = fz;
    auto b = fm;
    swap(a, b);
    int r = a % b;
    while (r != 0) {
        r = a % b;
        if (r == 0) break;
        a = b;
        b = r;
    }
    return b;
}

void CFraction::print() {
    int gcd = getGCD();
    gcd = gcd == 0 ? 1 : gcd;
    fz /= gcd;
    fm /= gcd;
    if (fm < 0) {
        fz = -fz;
        fm = -fm;
    }
    cout << fz << "/" << fm << endl;
}

void swap(int a, int b) {
    if (a < b) {
        auto tmp = a;
        a = b;
        b = tmp;
    }
}

int main() {
    int t, a, b, c, d;
    char _g;
    cin >> t;
    while (t--) {
        cin >> a >> _g >> b >> c >> _g >> d;
        CFraction f1(a, b), f2(c, d);
        f1.add(f2).print();
        f1.sub(f2).print();
        f1.mul(f2).print();
        f1.div(f2).print();
        cout << endl;
    }
    return 0;
}