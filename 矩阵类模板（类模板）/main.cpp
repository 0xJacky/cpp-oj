//
//  main.cpp
//  矩阵类模板（类模板）
//
//  Created by Jacky on 2020/12/28.
//  Copyright © 2020 Jacky. All rights reserved.
//
/*
 题目描述
 设计一个矩阵类模板Matrix，支持任意数据类型的数据。

 要求至少包含2个成员函数：矩阵转置函数transport、以及打印输出函数print

 编写main函数进行测试，调用类的成员函数完成转置和输出。

 输入
 第一行先输入t，表示有t个测试用例

 从第二行开始输入每个测试用例的数据。

 首先输入数据类型，I表示int，D表示double，C表示char，接着输入两个参数m和n，分别表示矩阵的行和列

 接下来输入矩阵的元素，一共m行，每行n个数据

 输出
 输出转置后的矩阵

 样例输入
 2
 I 2 3
 1 2 3
 4 5 6
 C 3 3
 a b c
 d e f
 g h i
 样例输出
 1 4
 2 5
 3 6
 a d g
 b e h
 c f i
 提示
 */
#include <iostream>
using namespace std;

template<typename T>
class Matrix {
    int m, n;
    T **p;
public:
    Matrix(int _m, int _n):m(_m), n(_n) {
        p = new T * [m];
        for (int i = 0; i < m; i++) {
            p[i] = new T[n];
            for (int j = 0; j < n; j++) {
                cin >> p[i][j];
            }
        }
    }
    
    void transport() {
        T **t = new T * [n];
        for (int i = 0; i < n; i++) {
            t[i] = new T[m];
            for (int j = 0; j < m; j++) {
                t[i][j] = p[j][i];
            }
        }
        delete [] p;
        p = t;
    }
    
    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    ~Matrix() {
        for (int i = 0; i < n; i++) {
            delete [] p[i];
        }
        delete [] p;
    }
};

int main() {
    int t, m, n;
    char type;
    cin >> t;
    while (t--) {
        cin >> type >> m >> n;
        if (type == 'I') {
            Matrix<int> matrix(m, n);
            matrix.transport();
            matrix.print();
        } else if (type == 'D') {
            Matrix<double> matrix(m, n);
            matrix.transport();
            matrix.print();
        } else if (type == 'C') {
            Matrix<char> matrix(m, n);
            matrix.transport();
            matrix.print();
        }
    }
    return 0;
}
