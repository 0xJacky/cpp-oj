//
//  main.cpp
//  货币兑换（指针与常量）
//
//  Created by Jacky on 2020/9/24.
//  Copyright © 2020 Jacky. All rights reserved.
//
/*
 题目描述
 设定以下汇率常量
 美元汇率为6.2619，表示1美元兑换6.2619元人民币
 欧元汇率为6.6744，表示1欧元兑换6.6744元人民币
 日元汇率为0.0516，表示1元日元兑换0.0516元人民币
 港币汇率为0.8065，表示1元港币币兑换0.8065元人民币
 定义一个常量指针，根据需求指针指向不同的汇率，然后计算出各种货币兑换为人民币的数量
 要求：不能直接使用汇率常量进行计算，必须使用常量指针，只能使用一个指针
 
 输入
 输入一个t表示有t个测试实例
 每行先输入一个字母，表示货币类型，然后再输入一个数字（正浮点数），表示货币数量
 D表示美元，E表示欧元，Y表示日圆，H表示港币
 依次输入t行
 
 输出
 每行输出兑换后的人民币数量，保留4位小数
 在C++中，输出指定精度的参考代码如下：
 
 #include <iomanip> //必须包含这个头文件
 #include <iostream>
 using namespace std;
 void main( )
 { double a =3.141596;
 cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位
 }
 
 样例输入
 4
 Y 10000
 D 88.3
 H 200
 E 73.1
 样例输出
 516.0000
 552.9258
 161.3000
 487.8986
 提示*/

#define USD 6.2619
#define EU 6.6744
#define JP 0.0516
#define HKD 0.8065
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const double usd = USD;
    const double eu = EU;
    const double jp = JP;
    const double hkd = HKD;

    int t;
    double input, ans;
    char type;

    cin >> t;
    while (t--) {
        cin >> type >> input;
        if (type == 'Y')
            ans = jp * input;
        else if (type == 'D')
            ans = usd * input;
        else if (type == 'E')
            ans = eu * input;
        else if (type == 'H')
            ans = hkd * input;
        cout << fixed << setprecision(4) << ans << endl;
    }

    return 0;
}