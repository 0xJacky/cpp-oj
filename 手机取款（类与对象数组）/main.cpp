//
//  main.cpp
//  手机取款（类与对象数组）
//
//  Created by Jacky on 2020/10/19.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 采用面向对象思想实现手机取款的过程
 假设银行账户有卡号、绑定手机号、动态密码、余额等属性，包含获取各种属性、校验动态密码、取款操作。属性全是整数数据。
 使用对象数组来保存n个银行账户。
 
 用户通过手机取款的步骤如下：(一般在主函数实现) 1、用户输入手机号，在n个银行账户中找到相应的银行账户。
 如果查找成功则往下执行，否则输出信息“手机号不存在”，不再往下执行； 2、用户输入动态密码，然后校验动态密码的是否正确
 如果密码正确则往下执行，否则输出信息“密码错误”，不再往下执行； 3、用户输入取款金额，然后执行取款操作
 如果余额不足就拒绝取款并给出信息“卡号XXX–余额不足”；如果取款成功给出信息“卡号XXX–余额YYY”，其中XXX表示卡号，YYY表示余额
 
 上述描述只是方便说明，可以一次输入所有数据再执行各个操作。
 输入
 第一行输入n，表示有n个账户
 下一行输入第一个账户的信息：卡号、绑定手机号、动态密码、余额 连续输入n行 接着输入k，表示要执行k次取款操作
 下一行输入手机号、动态密码、取款金额 连续输入k行
 
 输出
 输出k行，每行输出操作结果
 样例输入
 5
 1001 138111 111 1000
 1002 135222 222 200
 1003 136333 333 300
 1004 133444 444 400
 1005 132555 555 500
 4
 136333 333 600
 133444 444 300
 133555 555 200
 138111 222 900
 样例输出
 卡号1003--余额不足
 卡号1004--余额100
 手机号不存在
 密码错误
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;
map<unsigned int, unsigned int> m;

class Card {
protected:
    unsigned int cid, phone, pwd, balance;

public:
    Card(unsigned int _cid, unsigned int _phone, unsigned int _pwd,
         unsigned int _balance)
        : cid(_cid), phone(_phone), pwd(_pwd), balance(_balance) {}

    int checkPwd(unsigned int pwd) {
        if (this->pwd != pwd) {
            cout << "密码错误" << endl;
            return 0;
        }
        return 1;
    }

    unsigned int getPhone() {
        return phone;
    }

    void withdrawal(unsigned int money) {
        cout << "卡号" << cid << "--余额";
        if (money > balance) {
            cout << "不足" << endl;
            return;
        }
        balance -= money;
        cout << balance << endl;
    }
};

Card** database;

// if found, return > 0
int checkPhone(unsigned int phone) {
    int find = m[phone];
    if (!find) cout << "手机号不存在" << endl;
    return find;
}

int main() {
    int t, n;
    unsigned int cid, phone, pwd, balance, money;
    cin >> t;
    database = new Card*[t + 1];
    for (int i = 1; i <= t; i++) {
        cin >> cid >> phone >> pwd >> balance;
        m[phone] = i;
        database[i] = new Card(cid, phone, pwd, balance);
    }
    cin >> n;
    while (n--) {
        cin >> phone >> pwd >> money;
        auto i = checkPhone(phone);

        if (i && database[i]->checkPwd(pwd)) {
            database[i]->withdrawal(money);
        }
    }
    delete[] database;

    return 0;
}