//
//  main.cpp
//  超重青蛙
//
//  Created by Jacky on 2020/9/10.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 超重青蛙
 题目描述
 在青蛙王国，每个青蛙有着不同的体重。
 给出一组青蛙的体重，计算里面超出平均体重的青蛙数量。
 输入
 第一行输入参数T，表示有T个测试实例
 第二行输入参数n，表示这一组青蛙的数量，第三行输入n个青蛙的体重
 以此类推
 输出
 输出每一组青蛙中，超出平均体重的青蛙数量。
 样例输入
 2
 3
 1 2 3
 4
 10 20 30 40
 样例输出
 1
 2
 */

#define N 100
#include <iostream>
using namespace std;

int main() {
    int t, n;
    double wa[N], avg, ans;

    cin >> t;

    while (t--) {
        avg = 0;
        ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> wa[i];
            avg += wa[i];
        }

        avg /= n;

        for (int i = 0; i < n; i++) {
            if (wa[i] > avg) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}