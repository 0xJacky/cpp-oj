//
//  main.cpp
//  计算宝宝帐户收益(多重继承)
//
//  Created by Jacky on 2020/11/24.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
问题 C: 计算宝宝帐户收益(多重继承)
时间限制: 1 Sec  内存限制: 128 MB
提交: 413  解决: 142
[提交][状态][讨论版]
题目描述
定义一个类CPeople，具有身份号码(id,char[20])和姓名(name,char[10])两个数据成员，从CPeople类中再派生出CInternetUser类和CBankCustomer类,然后再从CInternetUser和CBankCustomer多重继承派生出CInternetBankCustomer类.。CInternetUser类有登录密码(password,char[20])属性和注册register(设置id, name和password)，登录login(判断输入的id与password是否与对象注册的相同)成员函数。CBankCustomer类有余额(balance,double)属性和开户openAccount(设置客户姓名和id)，存款deposit，取款withdraw以及缺省的构造函数。CInternetBankCustomer类包括有余额, 前一日余额, 当日收益，今日万元收益和上一日万元收益等5个数据成员，成员函数有缺省构造函数，存款和取款，设置万元收益，计算当日收益，登陆login(判断输入的id和密码是否与互联网用户的相同，同时从CBankCustomer继承的用户姓名和id要与从CInternetUser继承的相同)。CInternetBankCustomer类对象当日存款不计算收益，第2天开始才能计算收益，当日取款部分无收益。

  可参照如下所示的主函数来测试并设计输入数据：

int main()
{
int t, no_of_days, i;
char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
double money, interest;
char op_code;

//输入测试案例数t
     cin >> t;
     while (t--)
     {
//输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

//输入银行开户用户名,id
        cin >> b_xm >> b_id;

//输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

  CInternetBankCustomer ib_user;

      ib_user.registerUser(i_xm, i_id, i_mm);
      ib_user.openAccount(b_xm, b_id);

      if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
     {
         cout << "Password or ID incorrect" << endl;
         continue;
      }

//输入天数
      cin >> no_of_days;
      for (i=0; i < no_of_days; i++)
     {
      //输入操作代码, 金额, 当日万元收益
          cin >> op_code >> money >> interest;
          switch (op_code)
         {
            case 'S':  //从银行向互联网金融帐户存入
            case 's':
               if (ib_user.deposit(money) == 0)
               {
                  cout << "Bank balance not enough" << endl;
                  continue;
               }
               break;
          case 'T':  //从互联网金融转入银行帐户
          case 't':
              if (ib_user.withdraw(money) == 0)
             {
                 cout << "Internet bank balance not enough" << endl;
                 continue;
             }
             break;
          case 'D':  //直接向银行帐户存款
          case 'd':
               ib_user.CBankCustomer::deposit(money);
              break;
          case 'W':  //直接从银行帐户取款
           case 'w':
               if (ib_user.CBankCustomer::withdraw(money) == 0)
              {
                    cout << "Bank balance not enough" << endl;
                   continue;
              }
              break;
          default:
                cout << "Illegal input" << endl;
               continue;
         }
          ib_user.setInterest(interest);
          ib_user.calculateProfit();
//输出用户名,id
//输出银行余额
//输出互联网金融账户余额
          ib_user.print();
      }
   }

return 0;
}

输入
输入用户例数

输入第1个互联网用户注册时的用户名,id,登陆密码

输入第1个用户银行开户用户名,id

输入第1个互联网用户登陆时的id,登陆密码

输入第1个用户操作天数

循环输入操作代码(S,T,D,W)  金额  当日万元收益
......

输出
输出第1个用户名,id
输出第1个用户银行余额
输出第1个互联网金融账户余额
......

样例输入
2
zhangsan 1234567890 222222
zhangsan 1234567890
1234567890 222222
4
D 15000 0
s 8000 1.5
T 3000 1.55
w 2000 0
lisi 2014150000 abcdef
lisi 2014150000
2014150000 123456
样例输出
Name: zhangsan ID: 1234567890
Bank balance: 15000
Internet bank balance: 0

Name: zhangsan ID: 1234567890
Bank balance: 7000
Internet bank balance: 8000

Name: zhangsan ID: 1234567890
Bank balance: 10000
Internet bank balance: 5001.2

Name: zhangsan ID: 1234567890
Bank balance: 8000
Internet bank balance: 5001.98

Password or ID incorrect
提示
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class CPeople {
protected:
    char id[20];
    char name[10];
    CPeople(char* id, char* name) {
        strcpy(this->id, id);
        strcpy(this->name, name);
    }
};

class CInternetUser : public CPeople {
private:
    char password[20];
public:
    CInternetUser(char* id, char* name, char* pwd): CPeople(id, name) {
        strcpy(password, pwd);
    }
    bool login(char* id, char* pwd) {
        return (strcmp(id, this->id) == 0 && strcmp(pwd, password) == 0);
    }
};

class CBankCustomer : public CPeople {
protected:
    double balance = 0;
public:
    CBankCustomer(char* id, char* name): CPeople(id, name) {}
    void deposit(double money) {
        balance += money;
    }
    bool withdraw(double money) {
        if (balance - money < 0) return false;
        balance -= money;
        return true;
    }
};

class CInternetBankCustomer : public CInternetUser, public CBankCustomer {
protected:
    double _balance = 0, yesterday_balance = 0, today_income = 0,
        yesterday_interest = 0, today_interest = 0;
public:
    CInternetBankCustomer(char * i_xm, char* i_id, char* i_mm, char* b_xm, char* b_id)
        : CInternetUser(i_id, i_xm, i_mm), CBankCustomer(b_id,b_xm){}
    //从互联网金融转入银行帐户
    bool withdraw(double money) {
        if (_balance - money < 0) return false;
        _balance -= money;
        CBankCustomer::balance += money;
        return true;
    }
    //从银行向互联网金融帐户存入
    bool deposit(double money) {
        if (CBankCustomer::balance - money < 0) return false;
        CBankCustomer::balance -= money;
        _balance += money;
        return true;
    }
    void setInterest(double money) {
        yesterday_interest = today_interest;
        today_interest = money;
    }
    void calculateProfit() {
        //cout << yesterday_balance << " " << yesterday_interest << endl;
        today_income = yesterday_balance * yesterday_interest * 0.0001;
        //cout << today_income << endl;
        _balance += today_income;
        yesterday_balance = _balance;
    }
    void print() {
        cout << "Name: "<< CBankCustomer::name << " ID: " << CBankCustomer::id << endl;
        cout << "Bank balance: " << CBankCustomer::balance << endl;
        cout << "Internet bank balance: " << _balance << endl;
        cout << endl;
    }
};

int main()
{
    int t, no_of_days, i;
    char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
    double money, interest;
    char op_code;

    //输入测试案例数t
    cin >> t;
    while (t--)
    {
        //输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

        //输入银行开户用户名,id
        cin >> b_xm >> b_id;

        //输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user(i_xm, i_id, i_mm, b_xm, b_id);

        //ib_user.registerUser(i_xm, i_id, i_mm);
        //ib_user.openAccount(b_xm, b_id);

        if (!ib_user.login(ib_id, ib_mm) || strcmp(b_id, i_id) != 0 || strcmp(b_xm, i_xm) != 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        //输入天数
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++)
        {
            //输入操作代码, 金额, 当日万元收益
            cin >> op_code >> money >> interest;
            switch (op_code)
            {
            case 'S':  //从银行向互联网金融帐户存入
            case 's':
                if (!ib_user.deposit(money))
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T':  //从互联网金融转入银行帐户
            case 't':
                if (!ib_user.withdraw(money))
                {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D':  //直接向银行帐户存款
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W':  //直接从银行帐户取款
            case 'w':
                if (!ib_user.CBankCustomer::withdraw(money))
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            //输出用户名,id
            //输出银行余额
            //输出互联网金融账户余额
            ib_user.print();
        }
    }

    return 0;
}
