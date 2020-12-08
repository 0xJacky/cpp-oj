//
//  main.cpp
//  电话号码升位(拷贝构造函数)
//
//  Created by Jacky on 2020/10/27.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 定义一个电话号码类CTelNumber,包含1个字符指针数据成员,以及构造、析构、打印及拷贝构造函数。
 
 字符指针是用于动态创建一个字符数组，然后保存外来输入的电话号码
 
 构造函数的功能是为对象设置键盘输入的7位电话号码，
 
 拷贝构造函数的功能是用原来7位号码的对象升位为8位号码对象,也就是说拷贝构造的对象是源对象的升级.
 
 电话升位的规则是原2、3、4开头的电话号码前面加8，原5、6、7、8开头的前面加2。
 
 注意:电话号码只能全部是数字字符，且与上述情况不符的输入均为非法)
 
 输入
 测试数据的组数 t
 
 第一个7位号码
 
 第二个7位号码
 
 ......
 
 输出
 第一个号码升位后的号码
 
 第二个号码升位后的号码
 
 ......
 
 如果号码升级不成功，则输出报错信息，具体看示例
 
 样例输入
 3
 6545889
 3335656
 565655
 样例输出
 26545889
 83335656
 Illegal phone number
 */

#define N 100
#include <cstring>
#include <iostream>
using namespace std;

class CTelNumber {
public:
    char* tel = NULL;
    CTelNumber(char* t) {
        tel = new char[strlen(t) + 1];
        strcpy(tel, t);
    }
    CTelNumber(const CTelNumber& c) {
        unsigned long int len = strlen(c.tel);
        bool safe = true;

        if (c.tel[0] < '2' || c.tel[0] > '8') {
            safe = false;
        }

        for (unsigned long int i = 1; i < len; i++) {
            if (c.tel[i] < '0' || c.tel[i] > '9') {
                safe = false;
                break;
            }
        }

        if (len == 7 && safe) {
            tel = new char[len + 2];

            if (c.tel[0] >= '2' && c.tel[0] <= '4') {
                tel[0] = '8';
            } else if (c.tel[0] >= '5' && c.tel[0] <= '8') {
                tel[0] = '2';
            }

            tel[len + 1] = '\0';

            for (unsigned long int i = 0; i < len; i++) {
                tel[i + 1] = c.tel[i];
            }
        }
    }
    ~CTelNumber() {
        if (tel != NULL) {
            delete[] tel;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        char tel[N];
        cin >> tel;
        CTelNumber orig(tel), upgraded(orig);
        if (upgraded.tel == NULL) {
            cout << "Illegal phone number" << endl;
        } else {
            cout << upgraded.tel << endl;
        }
    }
    return 0;
}