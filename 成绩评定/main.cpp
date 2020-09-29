//
//  main.cpp
//  成绩评定
//
//  Created by Jacky on 2020/9/10.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 成绩评定
 题目描述
 对于给出0〜100之间的成绩进行成绩评定，大于等于85是A，75分至85以下是B，65至75分以下是C，60至65分以下是D，60分以下是F
 
 输入
 第一行输入T表示有T个测试实例
 第二行起，每行输入1个成绩，连续输入T行
 输出
 输出成绩等级
 样例输入
 3
 0
 55
 78
 样例输出
 F
 F
 B
 */
#include<iostream>
using namespace std;
int main() {
    int t;
    double s;
    cin >> t;
    while (t--) {
        cin >> s;
        if (s >= 85) cout << "A" << endl;
        else if (s >= 75 && s < 85) cout << "B" << endl;
        else if (s >= 65 && s < 75) cout << "C" << endl;
        else if (s >= 60 && s < 65) cout << "D" << endl;
        else cout << "F" << endl;
    }
    return 0;
}
