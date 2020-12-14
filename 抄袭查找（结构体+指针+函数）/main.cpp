//
//  main.cpp
//  抄袭查找（结构体+指针+函数）
//
//  Created by Jacky on 2020/9/28.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 已知一群学生的考试试卷，要求对试卷内容进行对比，查找是否有抄袭。
 
 每张试卷包含：学号（整数类型）、题目1答案（字符串类型）、题目2答案（字符串类型）、题目3答案（字符串类型）
 
 要求：使用结构体来存储试卷的信息。定义一个函数，返回值为一个整数，参数是两个结构体指针，函数操作是比较两张试卷的每道题目的答案，如果相同题号的答案相似度超过90%，那么就认为有抄袭，函数返回抄袭题号，否则返回0。相似度是指在同一题目中，两个答案的逐个位置上的字符两两比较，相同的数量大于等于任一个答案的长度的90%，就认为抄袭。
 
 输入
 第一行输入t表示有t张试卷
 第二行输入第1张试卷的学生学号
 第三行输入第1张试卷的题目1答案
 第四行输入第1张试卷的题目2答案
 第五行输入第1张试卷的题目3答案
 每张试卷对应4行输入
 依次输入t张试卷的数据
 
 输出
 在一行中，把发现抄袭的两个学号和题目号，数据之间用单个空格隔开
 如果发现是题目1抄袭，题目号为1，以此类推
 输出顺序按照输入的学号顺序进行输出
 
 样例输入
 5
 2088150555
 aabcdef11
 ZZ887766dd
 cc33447799ZZ
 2088150333
 abcdef00
 AABBCCDDEE
 ZZ668899cc
 2088150111
 AABBCCDDEE
 ZZ668899cc
 abcdef00
 2088150222
 AABBCFDDeE
 ZZ889966dd
 abcdef000
 2088150444
 aabcdef00
 AABBCDDDEE
 cc668899ZZ
 
 样例输出
 2088150333 2088150444 2
 2088150111 2088150222 3
 */

#define A 3
#define N 1000
#include <iostream>
#include <string>
using namespace std;

struct Paper {
    int id;
    string ans[A];
} paper[N];

unsigned long min(unsigned long a, unsigned long b) {
    return a < b ? a : b;
}

int judge(Paper* a, Paper* b) {
    for (int k = 0; k < A; k++) {
        unsigned long int ans1_len = a->ans[k].length(),
                          ans2_len = b->ans[k].length(), same = 0, shortlen;
        shortlen = min(ans1_len, ans2_len);

        for (int d = 0; d < shortlen; d++) {
            if (a->ans[k][d] == b->ans[k][d]) same++;
        }

        if (same >= ans1_len * 0.9 || same >= ans2_len * 0.9) {
            return k + 1;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> (paper + i)->id;
        for (int j = 0; j < A; j++) {
            cin >> (paper + i)->ans[j];
        }
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if ((paper + i)->id >= (paper + j)->id) continue;
            int ans_id = judge(paper + i, paper + j);
            if (ans_id) {
                cout << (paper + i)->id << " " << (paper + j)->id << " "
                     << ans_id << endl;
            }
        }
    }

    return 0;
}