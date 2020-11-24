 # 学生类定义（类和对象）
 ## 题目描述
 面向对象程序设计的中心就是把客观事物抽象为程序世界里一段段代码，校园里的主体是学生，泛泛的学生包含很多属性，比如姓名、学号、所在学院、专业、性别、住址、联系电话。。。。。。等等，有这些属性，需要操纵它们的动作，比如读取姓名、设置姓名、读取学号、设置学号。。。。。。等等，这就是我们课堂说的属性和方法，对于属性和方法，我们又有访问控制方式限制，标示为public、private、protected等，根据以上的信息，请给出一个完整的学生类定义：Student，并测试输出n个该类对象的各项属性值。
 
 ## 输入
 第一行表示要输入n个对象
 后续各行输入不同对象的各属性值，每个对象一行。
 
 ## 输出
 输出不同对象的各自属性
 每个对象占一行
 
 ## 样例输入
 2
 WangHai 2014150112 计算机 计算机科学与技术 男 南区215 13760222222
 LiBin 2013151292 计算机 软件工程 男 南区318 13677777777
 
 ## 样例输出
 WangHai 2014150112 计算机 计算机科学与技术 男 南区215 13760222222
 LiBin 2013151292 计算机 软件工程 男 南区318 13677777777
 */
#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    string id;
    string college;
    string major;
    string gender;
    string location;
    string phone;
public:
    Student& setName(string name) {
        this->name = name;
        return *this;
    }
    
    Student& setID(string id) {
        this->id = id;
        return *this;
    }
    
    Student& setCollege(string college) {
        this->college = college;
        return *this;
    }
    
    Student& setMajor(string major) {
        this->major = major;
        return *this;
    }
    
    Student& setGender(string gender) {
        this->gender = gender;
        return *this;
    }
    
    Student& setLocation(string location) {
        this->location = location;
        return *this;
    }
    
    Student& setPhone(string phone) {
        this->phone = phone;
        return *this;
    }
    
    Student& getName() {
        cout << name << " ";
        return *this;
    }
    
    Student& getID() {
        cout << id << " ";
        return *this;
    }
    
    Student& getCollege() {
        cout << college << " ";
        return *this;
    }
    
    Student& getMajor() {
        cout << major << " ";
        return *this;
    }
    
    Student& getGender() {
        cout << gender << " ";
        return *this;
    }
    
    Student& getLocation() {
        cout << location << " ";
        return *this;
    }
    
    Student& getPhone() {
        cout << phone;
        return *this;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string name, id, college, major, gender, location, phone;
        cin >> name >> id >> college >> major >> gender >> location >> phone;
        Student student;
        student.setName(name).setID(id).setCollege(college).setMajor(major).setGender(gender).setLocation(location).setPhone(phone);
        
        student.getName().getID().getCollege().getMajor().getGender().getLocation().getPhone();
        cout << endl;
    }
    return 0;
}
//
//  main.cpp
//  学生类定义（类和对象）
//
//  Created by Jacky on 2020/9/28.
//  Copyright © 2020 Jacky. All rights reserved.
//


/*#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string id;
    string college;
    string major;
    string gender;
    string location;
    string phone;
public:
    Student(string _name, string _id, string _college, string _major, string _gender, string _location, string _phone) {
        name = _name;
        id = _id;
        college = _college;
        major = _major;
        gender = _gender;
        location = _location;
        phone = _phone;
    }
    
    void info() {
        cout << name << " " << id << " " << college << " " << major << " " << gender << " " << location << " " << phone << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string name, id, college, major, gender, location, phone;
        cin >> name >> id >> college >> major >> gender >> location >> phone;
        Student student(name, id, college, major, gender, location, phone);
        student.info();
    }
    return 0;
}
