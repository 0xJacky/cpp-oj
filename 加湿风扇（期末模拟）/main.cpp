//
//  main.cpp
//  加湿风扇（期末模拟）
//
//  Created by Jacky on 2021/1/4.
//  Copyright © 2021 Jacky. All rights reserved.
//

/*
 题目描述
 已知家电有编号、功率的属性，属性都是整数，操作包括构造和打印等

 电风扇继承家电的特点，新增两个属性（整数）：风向和风力，其中风向为0表示定向吹风，状态为1表示旋转吹风。
 风扇包含两个新操作：风向控制和风力控制
 1、风向控制含一个整数参数，无返回，把风向设置为参数值，参数为0表示定向吹风，为1表示旋转吹风。
 2、风力控制含一个整数参数，无返回，把风力设置为参数值，参数表示风力级别，例如1级、2级、3级等。
 加湿器继承家电的特点，新增两个属性（浮点数）：实际水容量和最大水容量
 新增操作是预警，无参数，返回值为整数，当实际水容量不小于最大水容量的50%，则返回1；小于50%且不小于10%则返回2，小于10%则返回3
 加湿风扇继承了风扇和加湿器的特点，新增属性档位（整数）
 新增操作调整档位，含一个参数，无返回值，先设置档位为参数值，再调用风向控制和风力控制来设置相关属性，包括：
 1、参数为0，不做其他属性修改
 2、参数为1，设置定向吹风且风力1级
 3、参数为2，设置旋转吹风且风力2级
 4、参数为3，设置旋转吹风且风力3级
 档位只可能是0、1、2、3四个数值，其他数值忽略。
 加湿风扇重载打印操作，输出格式参考样本。输出要求如下：
 1、如果风向为0，则输出定向吹风，风向为1则输出旋转吹风。
 2、调用预警操作，并根据返回结果1、2、3输出不同信息，分别是：水量正常、水量偏低、水量不足
 程序要求
 1、采用虚拟继承机制实现上述电器的关系，明确谁是虚基类、基类、派生类
 2、基类和派生类的构造要考虑虚基类、基类的属性构造
 上述所有类属性都不是public，用面向对象思想和C++语言实现上述要求
 输入
 第一行输入t，表示有t个实例
 第二行输入一个加湿风扇的信息，依次包括编号、功率、风向、风力、实际水容量、最大水容量 档位
 第三行输入一个参数，表示调档操作的档位，然后执行调档操作。
 以此类推，输入t个实例
 输出
 对于每个实例，调用打印操作输出加湿风扇的最终状态

 样例输入
 3
 1001 1000 1 2 3 4 0
 1
 2002 2000 0 1 1 12 0
 3
 3003 3000 0 3 2 10 0
 0
 样例输出
 加湿风扇--档位1
 编号1001--功率1000W
 定向吹风--风力1级
 实际水容量3升--水量正常
 加湿风扇--档位3
 编号2002--功率2000W
 旋转吹风--风力3级
 实际水容量1升--水量不足
 加湿风扇--档位0
 编号3003--功率3000W
 定向吹风--风力3级
 实际水容量2升--水量偏低
 */

#include <iostream>
using namespace std;

class Appliances {
protected:
    int id;
    int power;

public:
    Appliances(int i, int p) : id(i), power(p) {}
    virtual void print() = 0;
};

class Fans : public Appliances {
protected:
    int direction;
    int windPower;

public:
    Fans(int id, int power, int d, int w)
        : Appliances(id, power), direction(d), windPower(w) {}
    void setDirection(int d) {
        direction = d;
    }

    void setWindPower(int p) {
        windPower = p;
    }
};

class Humidifier : public Appliances {
protected:
    double currentCapacity;
    double maxCapacity;

public:
    Humidifier(int id, int power, double c, double m)
        : Appliances(id, power), currentCapacity(c), maxCapacity(m) {}
    int warning() {
        if (currentCapacity >= maxCapacity * 0.5)
            return 1;
        else if (currentCapacity < maxCapacity * 0.5 &&
                 currentCapacity >= maxCapacity * 0.1)
            return 2;
        return 3;
    }
};

class HumidifyingFan : public Fans, public Humidifier {
    int gear;

public:
    HumidifyingFan(int id, int power, int direction, int windPower,
                   double currentCapacity, double maxCapacity)
        : Fans(id, power, direction, windPower),
          Humidifier(id, power, currentCapacity, maxCapacity) {}

    void setGear(int n) {
        gear = n;
        if (n == 1) {
            direction = 0;
            windPower = 1;
        } else if (n == 2 || n == 3) {
            direction = 1;
            windPower = n;
        }
    }
    void print() {
        static const char* transDirection[] = {"定向吹风", "旋转吹风"};
        static const char* transWarning[] = {"正常", "偏低", "不足"};
        cout << "加湿风扇--档位" << gear << endl;
        cout << "编号" << Fans::id << "--功率" << Fans::power << "W" << endl;
        cout << transDirection[direction] << "--风力" << windPower << "级"
             << endl;
        cout << "实际水容量" << currentCapacity << "升--水量"
             << transWarning[warning() - 1] << endl;
    }
};

int main() {
    int t, id, power, direction, windPower, currentCapacity, maxCapacity, n;
    cin >> t;
    while (t--) {
        cin >> id >> power >> direction >> windPower >> currentCapacity >>
            maxCapacity >> n;
        HumidifyingFan hf(id, power, direction, windPower, currentCapacity,
                          maxCapacity);
        cin >> n;
        hf.setGear(n);
        hf.print();
    }
    return 0;
}
