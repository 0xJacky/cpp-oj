//
//  main.cpp
//  新旧身份证(继承)
//
//  Created by Jacky on 2020/11/17.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 按下述方式定义一个日期类CDate和描述15位身份证号的旧身份证类COldID:
 
 class CDate
 
 {
 private:
 
 int year, month, day;
 
 public:
 
 CDate(int,int,int);
 
 bool check(); //检验日期是否合法
 
 bool isLeap();
 
 void print();
 
 };
 
 class COldID
 
 {
 private:
 
 char *p_id15, *p_name; //15位身份证号码，姓名
 
 CDate birthday; //出生日期
 
 public:
 
 COldID(char *p_idval, char *p_nameval, CDate &day);
 
 bool check(); //验证15位身份证是否合法
 
 void print();
 
 ~COldID();
 
 };
 
 然后以COldID为基类派生18位身份证号的新身份证类CNewID,并增加3个数据成员:p_id18(18位号码)、issueday(签发日期)和validyear(有效期，年数)，并重新定义check()和print()。
 
 身份证第18位校验码的生成方法：
 
 1、将身份证号码前17位数分别乘以7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2。然后将其相加。
 
 2、将17位数字和系数乘加的和除以11，得到余数。
 
 3、余数与校验码的对应关系为1,0,X,9,8,7,6,5,4,3,2。也即：如果余数是3，身份证第18位就是9。如果余数是2，身份证的最后一位号码就是X。
 
 主函数定义一个派生类对象，并用派生类对象调用check()，若返回false则输出“illegal
 id”否则调用print()输出身份证信息。check()对身份证合法性进行验证的规则：
 
 确认18位号码是从15位号码扩展的，且第18位校验码正确.
 
 身份证中的出生日期合法.
 
 身份证号码中不含非法字符.
 
 身份证号码的长度正确.
 
 身份证目前处于有效期内.
 
 输入
 测试数据的组数 t
 
 第一个人姓名、出生日期年月日、15位身份证号码、18位身份证号码、签发日期年月日、有效期(100年按长期处理)
 
 第二个人姓名、出生日期年月日、15位身份证号码、18位身份证号码、签发日期年月日、有效期(100年按长期处理)
 
 …
 
 输出
 第一个人姓名
 
 第一个人18位身份证号信息(号码、签发日期和有效期）或"illegal id"
 
 第二个人姓名
 
 第二个人18位身份证号信息(号码、签发日期和有效期）或"illegal id"
 
 …
 
 样例输入
 10
 AAAA 1988 2 28 440301880228113 440301198802281133 2006 1 20 20
 BBBB 1997 4 30 440301980808554 440301199808085541 2015 2 2 10
 CCCC 1920 5 8 530102200508011 53010219200508011X 1980 3 4 30
 DDDD 1980 1 1 340524800101001 340524198001010012 1998 12 11 20
 EEEE 1988 11 12 110203881112034 110203198811120340 2007 2 29 20
 FFFF 1964 11 15 432831641115081 432831196411150810 2015 8 7 100
 GGGG 1996 12 10 44030196121010 44030119961210109 2014 6 7 20
 HHHH 1988 7 21 440301880721X12 44030119880721X122 2006 5 11 20
 IIII 1976 3 30 440301760330098 440301197603300983 2003 4 15 20
 JJJJ 1955 9 5 440301550905205 440301195509051052 2004 6 4 100
 样例输出
 AAAA
 440301198802281133 2006年1月20日 20年
 BBBB
 illegal id
 CCCC
 illegal id
 DDDD
 illegal id
 EEEE
 illegal id
 FFFF
 432831196411150810 2015年8月7日 长期
 GGGG
 illegal id
 HHHH
 illegal id
 IIII
 illegal id
 JJJJ
 illegal id
 
 */

#define NOW 2015,4,7
#define N 100
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

class CDate
{
private:
    int year, month, day;
public:
    CDate() {}
    CDate(int y, int m, int d): year(y), month(m), day(d) {}
    
    bool check() {
        static int daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap()) {
            daysOfMonth[1] = 29;
        } else {
            daysOfMonth[1] = 28;
        }
        if (month < 1 || month > 12) {
            return false;
        }
        return (day <= daysOfMonth[month-1]);
    }
    
    bool isLeap() {
        return (year % 100 && year % 4 == 0) || year % 400 == 0;
    }
    
    void print() {
        cout << year << "年" << month << "月" << day << "日 ";
    }
    
    int getYear() {
        return year;
    }
    
    int getMonth() {
        return month;
    }
    
    int getDay() {
        return day;
    }
    
    bool operator>(CDate &c) {
        auto a = getSum();
        auto b = c.getSum();
        return a > b;
    }
    
    int getSum() {
        return year * 10000 + month * 100 + day;
    }
    
};

class COldID

{
private:
    
    char *p_id15 = NULL, *p_name = NULL; //15位身份证号码，姓名
    
    CDate birthday; //出生日期
    
public:
    COldID() {}
    COldID(char *p_idval, char *p_nameval, CDate &day): birthday(day) {
        p_id15 = new char[strlen(p_idval)+1];
        p_name = new char[strlen(p_nameval)+1];
        strcpy(p_id15, p_idval);
        strcpy(p_name, p_nameval);
    }
    
    bool check() {
        // 长度
        auto length = strlen(p_id15);
        if (length != 15) return false;
        // 非法字符
        int i = 0;
        while (*(p_id15 + i) != '\0') {
            if (*(p_id15 + i) < '0' || *(p_id15 + i) > '9') {
                return false;
            }
            i++;
        }
        // 生日合法
        if(!birthday.check()) return false;
        // 年月日
        auto sum = 1.9 * pow(10, 7);
        for (int i = 6; i < 12; i++) {
            sum += (*(p_id15 + i) - '0') * pow(10, fabs(4 - (i-7))) ;
        }
        //cout << "15:" <<sum << endl;
        //cout << birthday.getSum() << endl;
        if (sum != birthday.getSum()) return false;
        return true;
    }
    
    void print() {
        cout << p_id15;
    }
    
    ~COldID() {
        if (p_id15 != NULL) {
            delete [] p_id15;
        }
        if (p_name != NULL) {
            delete [] p_name;
        }
    }
    
};

class CNewID : public COldID {
private:
    CDate issueday;
    CDate birthday;
    unsigned int validyear;
    char * p_id18 = NULL;
    char * p_name = NULL;
    char * p_oid = NULL;
public:
    CNewID(char *p_oidval, char *p_idval, char *p_nameval, CDate &day, CDate & _issueday, unsigned int vy):
    birthday(day), issueday(_issueday), validyear(vy) {
        p_id18 = new char[strlen(p_idval)+1];
        p_oid = new char[strlen(p_oidval)+1];
        p_name = new char[strlen(p_nameval)+1];
        strcpy(p_id18, p_idval);
        strcpy(p_oid, p_oidval);
        strcpy(p_name, p_nameval);
    }
    
    bool check() {
        // 长度
        auto length = strlen(p_id18);
        if (length != 18) return false;
        // 非法字符
        int i = 0;
        while (*(p_id18 + i) != '\0') {
            if (*(p_id18 + i) < '0' || *(p_id18 + i) > '9') {
                return false;
            }
            i++;
        }
        // 从15位扩展而来
        for (int i = 0; i < 6; i++) {
            if (*(p_id18 + i) != *(p_oid + i)) return false;
        }
        for (int i = 6; i < 15 ; i++) {
            if (*(p_id18 + i + 2) != *(p_oid + i)) return false;
        }
        // 校验码
        int v = 0;
        static const int power[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        static const int code[] = {'1','0','X','9','8','7','6','5','4','3','2'};
        for (int i = 0; i < 17; i++) {
            v += (*(p_id18 + i) - '0') * power[i];
        }
        v %= 11;
        //cout << "v:" << v << endl;
        //cout << "*(p_id18+17):" << *(p_id18+17) << endl;
        if (code[v] != *(p_id18+17)) return false;
        // 生日合法 // 签发日期有效性
        if(!birthday.check() || ! issueday.check()) return false;
        // 年月日
        auto sum = 0;
        for (int i = 6; i <= 13; i++) {
            sum += (*(p_id18 + i) - '0') * pow(10, fabs(7 - (i-6))) ;
        }
        //cout << "18:" <<sum << endl;
        //cout << "18:" << birthday.getSum() << endl;
        if (sum != birthday.getSum()) return false;
        
        if (!issueday.check())
        // 有效期
        if (validyear != 100) {
            CDate current(NOW), expired(issueday.getYear()+validyear, issueday.getMonth(), issueday.getDay());
            if (expired > current) return false;
        }
        
        return true;
    }
    void print() {
        cout << p_id18;
    }
    ~CNewID() {
        if (p_id18 != NULL) {
            delete[] p_id18;
        }
        if (p_oid != NULL) {
            delete[] p_oid;
        }
        if (p_name != NULL) {
            delete[] p_name;
        }
    }
};

int main() {
    int t;
    cin >> t;
    char name[N], oid[N], nid[N];
    int y, m, d, vy, vm, vd, v;
    while (t--) {
        cin >> name >> y >> m >> d >> oid >> nid >> vy >> vm >> vd >> v;
        CDate a(y, m, d);
        COldID old(oid, name, a);
        CDate cvd(vy, vm, vd);
        CNewID _new(oid, nid, name, a, cvd, v);
        cout << name << endl;
        if (old.check() && _new.check()) {
            cout << nid << " ";
            cvd.print();
            if (v == 100) {
                cout << "长期" << endl;
            } else {
                cout << v << "年" << endl;
            }
        } else {
            cout << "illegal id" << endl;
        }
    }
    
    return 0;
}
