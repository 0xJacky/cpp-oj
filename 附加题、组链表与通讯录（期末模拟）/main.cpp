//
//  main.cpp
//  附加题、组链表与通讯录（期末模拟）
//
//  Created by Jacky on 2021/1/5.
//  Copyright © 2021 Jacky. All rights reserved.
//

/*
 题目描述
 组链表是一种常用的数据结构，它由数组加链表组成，往往用于信息检索中。

 每个链表由n个链表结点组成，每个链表都有头结点，头结点不存放实际数据，纯粹作为一个索引。
 所有链表的头结点组成一个数组，即数组的每个元素都是一个链表头结点，它的后面延伸着一个链表。
 例如一个通讯录包含五个联系人，每个联系人都有姓名和电话，每个联系人都对应一个链表结点。
 Tom 8111
 Any 1222
 Ken 2333
 Kim 2444
 Tim 8222
 我们先创建一个数组包含26个链表头结点，对应26个大写字母。因为有五个联系人，因此创建五个链表结点
 因为上述联系人的姓名的首字母为A\K\T，因此把五个链表结点分别加入到三个头结点之后，形成三个链表。
 其他字母的头结点因为无联系人，所以是空链表。构成组链表如下所示
 A--Any.1222
 K--Kim.2444--Ken.2333
 T--Tim.8222--Tom.8444
 现在使用组链表来实现通讯录，通讯录是多个联系人的信息集合，每个联系人都包含姓名和电话属性。

 每个联系人对应一个链表结点，姓名首字母相同的联系人放在同一个链表中。联系人的类定义基本写好，如下参考代码

 通讯录的类界面如下代码，操作包括：
 1、该类没有构造函数，使用输入函数Input实现数据的输入和通讯录的初始化
 2、打印函数Print，输出整个通讯录，输出格式参考样本
 3、插入新的联系人，重载运算符+=来实现，如果联系人姓名已经存在，则用新的电话覆盖旧电话
 注意：插入采用头插法，即新结点直接插入头结点之后
 4、查找联系人姓名，重载运算符()来实现，查找成功返回链表结点指针，失败返回NULL
 5、合并两个通讯录，重载运算符+来实现，合并结果放在第一个通讯录中，即左操作数。
 通讯录的合并实际上是两个相同首字母的链表合并。对于相同首字母的两个链表i和j合并过程如下：
 1）第二个链表j从头开始，取出联系人信息，在第一个链表i中查找。
 2）如果联系人已存在，则用第二个通讯录的电话覆盖第一个通讯录的电话
 3）如果联系人不存在，则把联系人插入到第一个链表i中
 程序要求
 1、联系人类定义和通讯录的类定义仅供参考，可自行定义
 2、主函数代码不能修改
 3、必须使用组链表来实现通讯录
 4、通讯录类的插入、查找、合并操作都必须基于链表结点来操作。
 ----参考代码----
```
 const int hmax=26;
 class Info { //联系人，用一个链表结点表示
     string name; //姓名
     int phoneNo; //电话
 public:
     Info* next;  //指向下一个结点
     Info(string tn= "no name", int pno=0)
     {    name = tn;
         phoneNo = pno;
         next = NULL;
     }
     void Print()
     {    cout<<name<<"--"<<phoneNo<<endl;    }
     //属性的get和set方法....自行定义
 };
 class PhoneBook {//组链表方式实现通讯录
     //....自行增加一些操作
     //提示：把插入和查找先写成内部函数，再被运算符重载调用，会更方便
 public:
     Info Table[hmax];    //链表头结点数组，对应26个大写字母
     //以下定义五个操作：输入Input、打印Print、插入、合并、查找
     //具体操作看前面说明
 };
 //...PhoneBook类成员函数，类外实现，自行编写
 //----主函数----
 int main()
 {    string tname;
     int i, tno;
     Info *p;
     PhoneBook pb;
     pb.Input(); //接收输入数据，初始化第一个通讯录
     //两次姓名查找
     for (i=0; i<2; i++)
     {    cin>>tname;
         p = pb(tname); //调用()运算符，实现查找
         if (p)    p->Print(); //查找成功，输出联系人信息
         else cout<<"查找失败"<<endl; //查找失败，输出提示信息
     }
     //一次插入
     cin>>tname>>tno;
     Info temp(tname, tno);
     pb += temp; //调用+=运算符，实现插入新联系人
     //通讯录合并
     PhoneBook pc;
     pc.Input(); //初始化第二个通讯录
     pb = pb+pc; //调用+运算符，实现合并
     
     pb.Print(); //输出所有操作后的通讯录
     return 0;
 }
 ```
 输入
 第一行输入n，表示第一个通讯录有n个联系人

 接着n行，每行输入一个联系人的信息：姓名、电话

 接着两行，每行输入一个联系人姓名，查找该联系人是否在通讯录中，并输出相应结果

 接着一行，输入一个联系人的信息：姓名、电话，执行插入操作

 接着一行，输入m，表示第二个通讯录有m个联系人

 接着m行，每行输入一个联系人的信息：姓名、电话

 输入完毕后，把第一个通讯录和第二个通讯录合并

 假定联系人姓名都是英文字母，且首字母大写。

 输出
 按照主函数执行过程输出
 样例输入
 4
 Tom 8111
 Any 1222
 Ken 2333
 Kim 2444
 Any
 Ben
 Tim 8222
 2
 Tom 8444
 Ann 1333
 样例输出
 Any--1222
 查找失败
 A--Ann.1333--Any.1222--
 K--Kim.2444--Ken.2333--
 T--Tim.8222--Tom.8444--

 */
#include <string>
#include <iostream>
using namespace std;

const int hmax = 26;
class Info {      //联系人，用一个链表结点表示
    string name;  //姓名
    int phoneNo;  //电话
public:
    Info* next;  //指向下一个结点
    Info(string tn = "no name", int pno = 0, Info * next = NULL) {
        name = tn;
        phoneNo = pno;
        this->next = next;
    }
    void Print() {
        cout << name << "--" << phoneNo << endl;
    }
    //属性的get和set方法....自行定义
    string getName() {
        return name;
    }
    int getPhoneNo() {
        return phoneNo;
    }
    void setPhoneNo(int pno) {
        phoneNo = pno;
    }
    ~Info() {
        if (next != NULL) {
            delete next;
        }
    }
};
class PhoneBook {  //组链表方式实现通讯录
    //....自行增加一些操作
    //提示：把插入和查找先写成内部函数，再被运算符重载调用，会更方便
private:
    Info * Find(string name) {
        int offset = name[0] - 'A';
        if (offset < 0 || offset > hmax) return NULL;
        for (auto i = &Table[offset]; i->next != NULL; i = i->next) {
            if (i->getName() == name) return i;
        }
        return NULL;
    }
    
    void Add(string name, int pno) {
        auto f = Find(name);
        if (f) {
            f->setPhoneNo(pno);
        } else {
            int offset = name[0]-'A';
            
            Info * next = new Info(Table[offset].getName(),
                                   Table[offset].getPhoneNo(), Table[offset].next);
            
            Table[offset] = Info(name, pno);
            Table[offset].next = next;
        }
    }
    
    void Merge(PhoneBook& pb) {
        for (int i = 0; i < hmax; i++) {
            
            for (auto j = &pb.Table[i]; j->next != NULL; j = j->next) {
                auto info = Find(j->getName());
                if (info) {
                    info->setPhoneNo(j->getPhoneNo());
                } else {
                    Add(j->getName(), j->getPhoneNo());
                }
            }
            
        }
    }
    
public:
    Info Table[hmax];  //链表头结点数组，对应26个大写字母
    //以下定义五个操作：输入Input、打印Print、插入、合并、查找
    //具体操作看前面说明
    void Input() {
        int t;
        string name;
        int tno;
        cin >> t;
        while (t--) {
            cin >> name >> tno;
            Add(name, tno);
        }
    }
    
    void Print() {
        for (int i = 0; i < hmax; i++) {
            if (Table[i].next == NULL) continue;
            char c = 'A' + i;
            cout << c << "--";
            for (auto j = &Table[i]; j->next != NULL; j = j->next) {
                cout << j->getName() << "." << j->getPhoneNo() << "--";
            }
            cout << endl;
        }
    }
    
    Info * operator()(string name) {
        return Find(name);
    }
    
    PhoneBook & operator+=(Info & pb) {
        Add(pb.getName(), pb.getPhoneNo());
        return *this;
    }
    
    PhoneBook& operator+(PhoneBook & pb) {
        Merge(pb);
        return *this;
    }
};


//...PhoneBook类成员函数，类外实现，自行编写
//----主函数----
int main() {
    string tname;
    int i, tno;
    Info* p;
    PhoneBook pb;
    pb.Input();  //接收输入数据，初始化第一个通讯录
    //两次姓名查找
    for (i = 0; i < 2; i++) {
        cin >> tname;
        p = pb(tname);  //调用()运算符，实现查找
        if (p)
            p->Print();  //查找成功，输出联系人信息
        else
            cout << "查找失败" << endl;  //查找失败，输出提示信息
    }
    //一次插入
    cin >> tname >> tno;
    Info temp(tname, tno);
    pb += temp;  //调用+=运算符，实现插入新联系人
    //通讯录合并
    PhoneBook pc;
    pc.Input();    //初始化第二个通讯录
    pb = pb + pc;  //调用+运算符，实现合并

    pb.Print();  //输出所有操作后的通讯录
    return 0;
}
