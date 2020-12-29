//
//  main.cpp
//  向量1（类和对象）
//
//  Created by Jacky on 2020/12/28.
//  Copyright © 2020 Jacky. All rights reserved.
//
/*
 题目描述
 n个有序数a1,a2,...,an组成的数组称为n维向量。 为n维向量定义CVector类，包含私有数据成员：

 int *data；//存储n维向量

 int n； //向量维数。

 方法有：无参构造函数，设置n=5,data的数据分别为0,1,2,3,4；构造函数，用虚参n1和数组a初始化n和data的数据；输出函数，按格式输出n维向量的值；析构函数。

 主函数输入数据，生成CVector对象并调用输出函数测试。

 输入
 输入n

 输入n维向量

 输出
 分别调用无参和带参构造函数生成2个CVector对象，输出它们的值。

 样例输入
 6
 10 1 2 3 4 5

 样例输出
 0 1 2 3 4
 10 1 2 3 4 5
 提示

 */

#include <iostream>
using namespace std;

class CVector {
    int *data;
    int n;
public:
    CVector(): n(5) {
        data = new int[n];
        for (int i = 0; i < n; i++) {
            data[i] = i;
        }
    }
    CVector(int n1, int a[]): n(n1) {
        data = new int[n];
        for (int i = 0; i < n; i++) {
            data[i] = a[i];
        }
    }
    void print() {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    ~CVector() {
        delete [] data;
    }
};

int main() {
    int n, *a;
    CVector v1;
    v1.print();
    
    cin >> n;
    a = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    CVector v2(n, a);
    v2.print();
    
    delete [] a;
    
    return 0;
}
