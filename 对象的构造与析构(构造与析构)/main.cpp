//
//  main.cpp
//  对象的构造与析构(构造与析构)
//
//  Created by Jacky on 2020/10/19.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 如下所示为类对象构造和析构过程中产生的输出,试完成类的定义和主函数的编写.
 输入
 测试数据的组数t
 第一组对象个数n1
 第二组对象个数n2
 .......
 输出
 Constructing object 1
 Constructing object 2
 ......
 Constructing object n1
 Destructing object n1
 ......
 Destructing object 2
 Destructing object 1
 Constructing object 1
 Constructing object 2
 ......
 Constructing object n2
 Destructing object n2
 ......
 Destructing object 2
 Destructing object 1
 ......
 样例输入
 2
 3
 4
 样例输出
 Constructing object 1
 Constructing object 2
 Constructing object 3
 Destructing object 3
 Destructing object 2
 Destructing object 1
 Constructing object 1
 Constructing object 2
 Constructing object 3
 Constructing object 4
 Destructing object 4
 Destructing object 3
 Destructing object 2
 Destructing object 1
 提示
 
 定义一个整型全局变量对构造和析构的对象进行计数或者用静态数据成员
 */

#include <iostream>
using namespace std;

class Object {
private:
    int id;
public:
    static int n;
    Object(int max) {
        id = ++n;
        cout << "Constructing object " << id << endl;
        if (id < max) Object o(max);
    }
    ~Object() {
        cout << "Destructing object " << id << endl;
    }
};

int Object::n = 0;

int main() {
    int t, max;
    cin >> t;
    while (t--) {
        Object::n = 0;
        cin >> max;
        Object o(max);
    }
    return 0;
}
