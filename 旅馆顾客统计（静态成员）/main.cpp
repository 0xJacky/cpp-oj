//
//  main.cpp
//  旅馆顾客统计（静态成员）
//
//  Created by Jacky on 2020/11/3.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 编写程序，统计某旅馆住宿客人的总数和收入总额。要求输入客人的姓名，输出客人编号（2015+顺序号，顺序号4位，如第1位为0001，第2位为0002，依此类推）、姓名、总人数以及收入总额。总人数和收入总额用静态成员，其他属性采用普通的数据成员。旅馆类声明如下：
 
 class Hotel {
 // 通过m_TotalCustNum来定义每个顾客的编号
 public:
 Hotel(char * a_Customer);
 //m_TotalCustNum++和m_CustomerNum按照m_TotalCustNum来生成
 
 ~Hotel(); // 记得 delete m_CustomerName
 void Display(); // 相应输出顾客姓名、顾客编号、总人数、总收入
 private:
 static int m_TotalCustNum; //顾客总人数
 static float m_TotalEearning; //旅店总收入
 static float m_Rent; // 每个顾客的房租
 char * m_CustomerName; // 顾客姓名
 int m_CustomerID; // 顾客编号
 };
 
 输入
 第1行：输入旅馆单个顾客房租
 
 第2行开始，依次输入顾客姓名，0表示输入结束。
 
 输出
 每行依次输出顾客信息和当前旅馆信息。包括顾客姓名，顾客编号，旅馆当前总人数，旅馆当前总收入。
 
 样例输入
 150
 张三 李四 王五 0
 样例输出
 张三 20150001 1 150
 李四 20150002 2 300
 王五 20150003 3 450
 */

#define _CRT_SECURE_NO_WARNINGS
#define N 100
#define PERFIX 2015000
#include <cstring>
#include <iostream>
using namespace std;

class Hotel {
    // 通过m_TotalCustNum来定义每个顾客的编号
public:
    Hotel(char* a_Customer);
    //m_TotalCustNum++和m_CustomerNum按照m_TotalCustNum来生成
    static void setRent(float _rent);
    ~Hotel();  // 记得 delete m_CustomerName
    void Display();  // 相应输出顾客姓名、顾客编号、总人数、总收入
private:
    static int m_TotalCustNum;     //顾客总人数
    static float m_TotalEearning;  //旅店总收入
    static float m_Rent;           // 每个顾客的房租
    char* m_CustomerName;          // 顾客姓名
    int m_CustomerID;              // 顾客编号
};

int Hotel::m_TotalCustNum = 0;
float Hotel::m_TotalEearning = 0;
float Hotel::m_Rent = 0;

Hotel::Hotel(char* a_Customer) {
    m_CustomerName = new char[strlen(a_Customer) + 1];
    strcpy(m_CustomerName, a_Customer);
    m_CustomerID = PERFIX + (++Hotel::m_TotalCustNum);
    m_TotalEearning += m_Rent;
}

void Hotel::setRent(float _rent) {
    Hotel::m_Rent = _rent;
}

void Hotel::Display() {
    cout << m_CustomerName << " " << m_CustomerID << " "
         << Hotel::m_TotalCustNum << " " << Hotel::m_TotalEearning << endl;
}

Hotel::~Hotel() {
    delete[] m_CustomerName;
}

int main() {
    char name[100] = {'A'};
    float rent;
    cin >> rent;
    Hotel::setRent(rent);

    while (true) {
        cin >> name;
        if (strcmp(name, "0") == 0) {
            break;
        }
        Hotel hotel(name);
        hotel.Display();
    }

    return 0;
}