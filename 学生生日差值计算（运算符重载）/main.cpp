//
//  main.cpp
//  学生生日差值计算（运算符重载）
//
//  Created by Jacky on 2020/12/15.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义一个学生类Student，包含该学生的姓名、出生年、月、日 ，重定义 “-”号实现两个学生之间相差多少天的比较。并利用重载的“-”运算符，求所有学生中年龄相差最大的两个人的名字以及相差天数。
 输入
 第一行：输入所需要输入的学生个数；
 第二行开始，依次输入每个学生的姓名、出生年、月、日。
 输出
 输出年龄相差最大的两个人的名字以及相差天数。
 样例输入
 3
 Tom 1995 1 1
 Joe 1995 2 28
 Jimmy 1996 1 8
 样例输出
 Tom和Jimmy年龄相差最大，为372天。
 提示

*/

#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int year;
    int month;
    int day;
    Student(string n, int y, int m, int d)
        : name(n), year(y), month(m), day(d) {}

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100) || year % 400 == 0;
    }

    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100) || y % 400 == 0;
    }

    int *getDaysOfMonth() {
        static int daysOfMonth[] = {31, 28, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};
        if (isLeapYear()) {
            daysOfMonth[1] = 29;
        } else {
            daysOfMonth[1] = 28;
        }
        return daysOfMonth;
    }

    int getDaysOfYear() {
        return isLeapYear() ? 366 : 365;
    }

    int getDaysOfYear(int i) {
        return isLeapYear(i) ? 366 : 365;
    }

    int getDaysFromYearStart() {
        int *daysOfMonth = getDaysOfMonth();
        int sum = day;
        for (int i = 0; i < month - 1; i++) {
            sum += daysOfMonth[i];
        }
        return sum;
    }

    int operator-(Student &s) {
        auto a = -getDaysFromYearStart();
        for (int i = year; i < s.year; i++) {
            a += getDaysOfYear(i);
        }
        auto b = s.getDaysFromYearStart();
        return a + b;
    }

    int dateToInt() {
        return year * 1000 + month * 100 + day;
    }

    bool operator>(Student &s) {
        return dateToInt() > s.dateToInt();
    }
};

int main() {
    int t, y, m, d;
    string name;
    cin >> t;
    Student **p = new Student *[t];
    for (int i = 0; i < t; i++) {
        cin >> name >> y >> m >> d;
        p[i] = new Student(name, y, m, d);
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t - i - 1; j++) {
            if (*p[j + 1] > *p[j]) {
                Student *tmp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = tmp;
            }
        }
    }
    cout << p[t - 1]->name << "和" << p[0]->name << "年龄相差最大，为"
         << *p[t - 1] - *p[0] << "天。" << endl;
    return 0;
}
