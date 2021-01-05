//
//  main.cpp
//  机密模板（期末模拟）
//
//  Created by Jacky on 2021/1/4.
//  Copyright © 2021 Jacky. All rights reserved.
//

/*
 题目描述
 加密机制包括明文、密文、密钥。用密钥对明文进行加密后就得到密文。
 在古典加密机制中，偏离值是一种常见的方法，加密过程为
 1、在已知数据中找出最大值
 2、用最大值减去各个数值，得到相应的偏离值
 3、偏离值加上密钥就得到密文
 例如明文为1 2 3 4 5，密钥是10，加密过程为：
 1、找出明文的最大值是5
 2、用5减去明文的各个数值，得到偏离值4 3 2 1 0
 3、用偏离值加上密钥，得到密文14 13 12 11 10
 定义一个函数模板，名为max，参数包括数组和数组长度，返回值是数组中的最大值，要求支持整数、浮点数和字符三种类型。

 用类模板定义一个加密类，包含四个属性：明文、密文、密钥、长度，前三个属性都是同一种类型，长度是整数。长度是指明文的长度。
 类模板包含操作构造、加密、打印，说明如下：
 1、加密是调用函数模板max得到数组最大值，按照前面的方法使用最大值和密钥进行加密，得到密文
 2、打印是输出密文
 要求类模板支持整数、浮点数和字符三种类型。
 参考代码给出了加密类界面（只支持整数类型）、主函数（支持三种数据类型），程序要求
 1、根据要求编写函数模板max
 2、使用类模板方法改造加密类界面，不能增加任何属性和操作，必须在类外实现构造函数和加密方法
 3、主函数不能有任何修改
 上述所有类属性都不是public，用面向对象思想和C++语言实现上述要求
 ----参考代码----
```
 //只支持整数类型的加密类界面
 class Cryption {
     int ptxt[100];    //明文
     int ctxt[100];    //密文
     int key;    //密钥
     int len;    //长度
 public:
     Cryption(int tk, int tt[], int tl); //参数依次对应密钥、明文、长度
     void Encrypt(); //加密
     void Print() //打印，无需改造
     {    int i;
         for (i=0; i<len-1; i++)
             cout<<ctxt[i]<<" ";
         cout<<ctxt[i]<<endl;
     }
 };
 //支持三种类型的主函数
 int main()
 {    int i;
     int length; //长度
     int ik, itxt[100];
     double dk, dtxt[100];
     char ck, ctxt[100];
     //整数加密
     cin>>ik>>length;
     for (i=0; i<length; i++)
         cin>>itxt[i];
     Cryption<int> ic(ik, itxt, length);
     ic.Encrypt();
     ic.Print();
     //浮点数加密
     cin>>dk>>length;
     for (i=0; i<length; i++)
         cin>>dtxt[i];
     Cryption<double> dc(dk, dtxt, length);
     dc.Encrypt();
     dc.Print();
     //字符加密
     cin>>ck>>length;
     for (i=0; i<length; i++)
         cin>>ctxt[i];
     Cryption<char> cc(ck, ctxt, length);
     cc.Encrypt();
     cc.Print();
     
     return 0;
 }
 ```
 输入
 第一行输入整数类型的信息，包括密钥、长度、明文
 第二行输入浮点数类型的信息，包括密钥、长度、明文
 第三行输入字符类型的信息，包括密钥、长度、明文
 输出
 三行分别输出三种类型的密文

 样例输入
 10 5 1 2 3 4 5
 11.11 4 1.1 2.2 3.3 4.4
 O 3 a b c
 样例输出
 14 13 12 11 10
 14.41 13.31 12.21 11.11
 Q P O

 */

#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
T max(T arr[], int len) {
    T max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

template <typename T>
class Cryption {
    T ptxt[100];  //明文
    T ctxt[100];  //密文
    T key;        //密钥
    int len;      //长度
public:
    //参数依次对应密钥、明文、长度
    Cryption(T tk, T tt[], int tl): len(tl) {
        for (int i = 0; i < tl; i++) {
            ptxt[i] = tt[i];
        }
        key = tk;
    }
    
    //加密
    void Encrypt() {
        T maxValue = max(ptxt, len);
        for (int i = 0; i < len; i++) {
            ctxt[i] = (T)fabs(ptxt[i]-maxValue) + key;
        }
    }
    
    void Print()  //打印，无需改造
    {
        int i;
        for (i = 0; i < len - 1; i++) cout << ctxt[i] << " ";
        cout << ctxt[i] << endl;
    }
};
//支持三种类型的主函数
int main() {
    int i;
    int length;  //长度
    int ik, itxt[100];
    double dk, dtxt[100];
    char ck, ctxt[100];
    //整数加密
    cin >> ik >> length;
    for (i = 0; i < length; i++) cin >> itxt[i];
    Cryption<int> ic(ik, itxt, length);
    ic.Encrypt();
    ic.Print();
    //浮点数加密
    cin >> dk >> length;
    for (i = 0; i < length; i++) cin >> dtxt[i];
    Cryption<double> dc(dk, dtxt, length);
    dc.Encrypt();
    dc.Print();
    //字符加密
    cin >> ck >> length;
    for (i = 0; i < length; i++) cin >> ctxt[i];
    Cryption<char> cc(ck, ctxt, length);
    cc.Encrypt();
    cc.Print();

    return 0;
}
