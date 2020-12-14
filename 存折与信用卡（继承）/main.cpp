//
//  main.cpp
//  存折与信用卡（继承）
//
//  Created by Jacky on 2020/11/24.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义一个存折类CAccount，存折类具有帐号（account,long）、姓名（name,char[10])、余额（balance,float）等数据成员，可以实现存款（deposit,操作成功提示“savingok!”)、取款（withdraw，操作成功提示“withdrawok!”）和查询余额（check）的操作，取款金额必须在余额范围内，否则提示“sorry! overbalance!”。从存折类派生出信用卡类CCreditcard，信用卡类增加了透支限额（limit,float）一项数据成员，对取款操作进行修改，允许在限额范围内透支金额，超出范围取款提示“sorry!
 over limit!”。

 编写主函数，建立这两个类的对象并测试之。

 1.对于存折类，输入账号、姓名、余额后，按照查询余额、存款、查询余额、取款、查询余额的顺序调用类方法并输出。

 2.对于信用卡类，输入账号、姓名、余额、透支限额后，按照查询余额、存款、查询余额、取款、查询余额的顺序调用类方法并输出。

 输入
 账号 姓名 余额

 存款金额

 取款金额

 账号 姓名 余额 透支限额

 存款金额

 取款金额

 输出
 账户余额

 存款操作结果

 账户余额

 取款操作结果

 账户余额

 账户余额

 存款操作结果

 账户余额

 取款操作结果

 账户余额

 样例输入
 1000 Tom 1000
 500
 1000
 2000 John 500 500
 500
 1501
 样例输出
 balance is 1000
 saving ok!
 balance is 1500
 withdraw ok!
 balance is 500
 balance is 500
 saving ok!
 balance is 1000
 sorry! over limit!
 balance is 1000
 */

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class CAcount {
protected:
    long account;
    char name[10];
    float balance;

public:
    CAcount(long a, char* n, float b) : account(a), balance(b) {
        strcpy(name, n);
    }
    void deposit(float money) {
        check();
        balance += money;
        cout << "saving ok!" << endl;
    }
    virtual void withdraw(float money) {
        if (balance - money < 0) {
            cout << "sorry! over balance!" << endl;
            return;
        }
        balance -= money;
        cout << "withdraw ok!" << endl;
    }
    void check() {
        cout << "balance is " << balance << endl;
    }
};

class CCreditCard : public CAcount {
private:
    float limit;

public:
    CCreditCard(long a, char* n, float b, float limit)
        : CAcount(a, n, b), limit(limit) {}
    void withdraw(float money) {
        if (balance - money < 0 && -(balance - money) > limit) {
            cout << "sorry! over limit!" << endl;
            return;
        }
        balance -= money;
        cout << "withdraw ok!" << endl;
    }
};

void test(CAcount& a, float deposit, float withdraw) {
    a.deposit(deposit);
    a.check();
    a.withdraw(withdraw);
    a.check();
}

int main() {
    long a;
    char name[10];
    float balance, limit, deposit, withdraw;

    cin >> a >> name >> balance >> deposit >> withdraw;
    CAcount account(a, name, balance);
    test(account, deposit, withdraw);
    cin >> a >> name >> balance >> limit >> deposit >> withdraw;
    CCreditCard cc(a, name, balance, limit);
    test(cc, deposit, withdraw);
    return 0;
}