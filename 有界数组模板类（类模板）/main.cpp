//
//  main.cpp
//  有界数组模板类（类模板）
//
//  Created by Jacky on 2020/12/28.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
题目描述
编写有界数组模板BoundArray（即检查对数组元素下标引用并在下标越界时终止程序的执行），能够存储各种类型的数据。要求实现对数组进行排序的方法sort，及对排序后的数组进行查找的方法search。

输入
第一行先输入t，表示有t个测试用例

从第二行开始输入每个测试用例的数据。

首先输入数据类型，I表示int，D表示double，C表示char，接着输入数组的元素个数

然后输入每个元素

最后输入要查找的元素

输出
首先输出从小到大排序的元素

然后输出查找元素的结果，找到则输出下标，没找到则输出-1

样例输入
2
I 2
1 2
2
D 3
3.5 6.2 2.9
2.1
样例输出
1 2
1
2.9 3.5 6.2
-1
*/

#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class BoundArray {
    T *p;
    int length;

public:
    BoundArray(int l) : length(l) {
        p = new T[length];
        for (int i = 0; i < length; i++) {
            cin >> p[i];
        }
    }
    void Sort() {
        sort(p, p + length);
    }
    void print() {
        for (int i = 0; i < length; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    void find(T target) {
        int index = -1;
        for (int i = 0; i < length; i++) {
            if (target == p[i]) index = i;
        }
        cout << index << endl;
    }
    ~BoundArray() {
        delete[] p;
    }
};

int main() {
    int t, m, n;
    double d;
    char type, c;
    cin >> t;
    while (t--) {
        cin >> type >> m;
        if (type == 'I') {
            BoundArray<int> boundArray(m);
            boundArray.Sort();
            boundArray.print();
            cin >> n;
            boundArray.find(n);

        } else if (type == 'D') {
            BoundArray<double> boundArray(m);
            boundArray.Sort();
            boundArray.print();
            cin >> d;
            boundArray.find(d);
        } else if (type == 'C') {
            BoundArray<char> boundArray(m);
            boundArray.Sort();
            boundArray.print();
            cin >> c;
            boundArray.find(c);
        }
    }
    return 0;
}
