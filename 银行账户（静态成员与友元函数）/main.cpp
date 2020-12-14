//
//  main.cpp
//  银行账户（静态成员与友元函数）
//
//  Created by Jacky on 2020/11/3.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 银行账户类的基本描述如下：
 class Account { // 银行账户类
 public:
 Account(string accno, string name, float balance);
 ~Account();
 void Deposit(float amount); // 存款
 void WithDraw(float amount); // 取款
 float GetBalance(); // 获取账户余额
 void Show(); // 显示账户基本信息
 static int GetCount(); // 获取账户数
 static float GetInterestRate(); // 获取利率
 private:
 static int count; // 银行账户数量
 static float InterestRate; // 利率
 string _accno, _accname; // 账户与户名
 float _balance; // 账户余额
 };
 要求如下：
 
 实现该银行账户类
 
 为账户类Account增加一个友元函数，实现账户结息，要求输出结息后的余额（结息余额=账户余额+账户余额*利率）。
 友元函数声明形式为 friend void Update(Account& a);
 
 在main函数中，定义一个Account类型的指针数组，让每个指针指向动态分配的Account对象，并调用成员函数测试存款、取款、显示等函数，再调用友元函数测试进行结息。
 
 大家可以根据实际需求在类内添加其他方法，也可以修改成员函数的参数设置
 
 输入
 第1行：利率
 第2行：账户数目n
 第3行开始，每行依次输入一个账户的“账号”、“姓名”、“余额”、存款数，取款数。
 
 输出
 第1行开始，每行输出一个账户的相关信息，包括账号、姓名、存款后的余额、存款后结息余额、取款后余额。
 
 最后一行输出所有账户的余额。
 
 样例输入
 0.01
 3
 201501 张三 10000 1000 2000
 201502 李四 20000 2000 4000
 201503 王二 80000 4000 6000
 样例输出
 201501 张三 11000 11110 9110
 201502 李四 22000 22220 18220
 201503 王二 84000 84840 78840
 106170
 */

#include <iostream>
#include <string>
using namespace std;

class Account {  // 银行账户类
public:
    Account();
    Account(string accno, string name, float balance);
    ~Account();
    void Deposit(float amount);   // 存款
    void WithDraw(float amount);  // 取款
    float GetBalance();           // 获取账户余额
    void Show();                  // 显示账户基本信息
    static int GetCount();        // 获取账户数
    static void SetInterestRate(float rate);
    static float GetTotal();
    friend void Update(Account& a);

private:
    static int count;                  // 银行账户数量
    static float InterestRate, Total;  // 利率&所有账户余额
    string _accno, _accname;           // 账户与户名
    float _balance;                    // 账户余额
};
int Account::count = 0;
float Account::InterestRate;
float Account::Total = 0;

Account::Account() {
    Account::count++;
}

Account::Account(string accno, string name, float balance)
    : _accno(accno), _accname(name), _balance(balance) {
    Account::Total += _balance;
    Account::count++;
}

Account::~Account() {
    Account::Total -= _balance;
    Account::count--;
}

void Account::Deposit(float amount) {
    _balance += amount;
    Account::Total += amount;
    cout << _balance << " ";
}

void Account::WithDraw(float amount) {
    _balance -= amount;
    Account::Total -= amount;
    cout << _balance;
}

void Account::Show() {
    cout << _accno << " " << _accname << " ";
}

float Account::GetBalance() {
    return _balance;
}

float Account::GetTotal() {
    return Account::Total;
}

void Account::SetInterestRate(float rate) {
    Account::InterestRate = rate;
}

void Update(Account& a) {
    auto tmp = (a._balance * Account::InterestRate);
    a._balance += tmp;
    Account::Total += tmp;
    cout << a._balance << " ";
}

int main() {
    float ir, balance, deposit, withdraw;
    int n;
    string accno, accname;
    Account** accounts;
    cin >> ir >> n;
    Account::SetInterestRate(ir);
    accounts = new Account*[n];
    for (int i = 0; i < n; i++) {
        cin >> accno >> accname >> balance >> deposit >> withdraw;
        accounts[i] = new Account(accno, accname, balance);
        accounts[i]->Show();
        accounts[i]->Deposit(deposit);
        Update(*accounts[i]);
        accounts[i]->WithDraw(withdraw);
        cout << endl;
    }
    cout << Account::GetTotal() << endl;
    delete[] accounts;
    return 0;
}