//
//  main.cpp
//  密钥加密法（指针应用）
//
//  Created by Jacky on 2020/9/24.
//  Copyright © 2020 Jacky. All rights reserved.
//
/*
 题目描述
 有一种方式是使用密钥进行加密的方法，就是对明文的每个字符使用密钥上对应的密码进行加密，最终得到密文
 例如明文是abcde，密钥是234，那么加密方法就是a对应密钥的2，也就是a偏移2位转化为c；明文b对应密钥的3，就是b偏移3位转化为e，同理c偏移4位转化为g。这时候密钥已经使用完，那么又重头开始使用。因此明文的d对应密钥的2，转化为f，明文的e对应密钥的3转化为h。所以明文abcde，密钥234，经过加密后得到密文是cegfh。
 如果字母偏移的位数超过26个字母范围，则循环偏移，例如字母z偏移2位，就是转化为b，同理字母x偏移5位就是转化为c
 要求：使用三个指针p、q、s分别指向明文、密钥和密文，然后使用指针p和q来访问每个位置的字符，进行加密得到密文存储在指针s指向的位置。
 除了变量定义和输入数据，其他过程都不能使用数组下标法，必须使用三个指针来访问明文、密钥和密文。
 提示：当指针q已经移动到密钥的末尾，但明文仍然没有结束，那么q就跳回密钥头
 
 输入
 第一行输入t表示有t个测试实例
 第二行输入一个字符串，表示第一个实例的明文
 第三行输入一个数字串，表示第一个实例的密钥
 依次输入t个实例
 
 输出
 每行输出加密后的密文
 
 样例输入
 2
 abcde
 234
 XenOS
 56
 样例输出
 cegfh
 CksUX
 提示
 */

#define N 1000
#include <iostream>
using namespace std;

int length(char* s) {
    int i = 0;
    while (*s++ != '\0') i++;
    return i;
}
// - '0'
int main() {
    int t, pw_length;
    cin >> t;
    while (t--) {
        char input[N], pw[N], encrypt[N], en, tmp;
        char *p = input, *q = pw, *s = encrypt;
        cin >> input >> pw;
        pw_length = length(pw);
        int i = 0, j = 0;
        while (*(p + i) != '\0') {
            if (j + 1 > pw_length) j = 0;
            tmp = *(p + i) + *(q + j) - '0';
            if (tmp > 'A' && tmp > 'Z' && tmp < 'a') {
                tmp = 'Z' - tmp;
                en = tmp + 'A' + *(q + j) - '0';
            } else if (tmp > 'a' && tmp > 'z') {
                tmp = 'z' - tmp;
                en = tmp + 'a' + *(q + j) - '0';
            } else {
                en = tmp;
            }

            *(s + i) = en;

            i++;
            j++;
        }

        *(s + i) = '\0';

        cout << s << endl;
    }
    return 0;
}