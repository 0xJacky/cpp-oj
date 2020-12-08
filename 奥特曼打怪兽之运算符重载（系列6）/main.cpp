//
//  main.cpp
//  奥特曼打怪兽之运算符重载（系列6）
//
//  Created by Jacky on 2020/12/8.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述




 在奥特曼打怪兽的过程中，会有各种魔法袋，奥特曼可以捡起这些魔法袋，对自己施加不同的魔法。魔法袋的种类和功能描述如下：

 1． “好事成双”魔法袋(重载+
+)：使自己的等级翻倍，生命值恢复满血，为翻倍后等级的10倍，攻击力提升为翻倍后等级的3倍，经验和钱财翻倍。

 2． “祸不单行”魔法袋(重载–
–)：使自己的生命值、攻击力、经验和钱财缩减为原来的一半。

 3． “吸星大法”魔法袋(重载
<)：所当前所打怪兽等级小于奥特曼，则奥特曼的生命值、攻击力、经验和钱财将增加怪兽相应属性的一半。

 4． “有缘相会”魔法袋(重载
==)：所当前所打怪兽等级等于奥特曼，则奥特曼的生命值、攻击力、经验和钱财将增加怪兽相应属性的取值。

 以成员函数方式为奥特曼重载以上方法。

 另外以友元方式为奥特曼重载运算符<<，使它能够支持与普通类型数据一样的输出方式。



 重新组织和修改前面实验的代码，利用运算符重载实现以下内容，使得下面的main函数能正确执行并输出相关信息。

 *******************************************************************************
```
 int main(){

     int ograd;
cin>>ograd;//输入奥特曼的等级值，利用等级值，声明一个奥特曼对象。

     Ultraman uobj(ograd);

     cout<<uobj;  //显示奥特曼对象初始状态



     int t;   cin>>t;//输入测试次数

     while(t--){

          char c=0;

          while(1){

              cin>>c;//输入要使用的魔法袋，G代表好事成双，B代表祸不单行，X代表吸星大法，Y代表有缘相会

              if(c=='G')   {

                   cout<<"****好事成双****"<<endl;

                   ++uobj;

                   cout<<"****成功翻倍****"<<endl;

                   break;

              }

              else if(c=='B') {

                   cout<<"****祸不单行****"<<endl;

                   --uobj;

                   cout<<"****不幸减半****"<<endl;

                   break;

              }

              else if(c=='X') {

                   int
r;cin>>r;//输入怪兽的等级值，利用等级值，声明一个怪兽对象并显示对象初始状态。

                   Monster mobj(r);

                  mobj.display();

                   cout<<"****吸星大法****"<<endl;

                   if(uobj<mobj) cout<<"****大功告成****"<<endl;

                   else cout<<"****尚未成功****"<<endl;

                   break;

              }

              else if(c=='Y'){

                   int
r;cin>>r;//输入怪兽的等级值，利用等级值，声明一个怪兽对象并显示对象初始状态。

                   Monster mobj(r);

                   mobj.display();

                   cout<<"****有缘相会****"<<endl;

                   if(uobj==mobj)cout<<"****有缘有分****"<<endl;

                   else cout<<"****无缘无分****"<<endl;

                   break;

              }

              else cout<<"请重新输入魔法袋类型"<<endl;

          }

          cout<<uobj;

     }

     return 0;

 }
```
 输入
 第1行输入奥特曼等级

 第2行输入测试次数

 对于每次测试，输入魔法袋类别（G代表好事成双，B代表祸不单行，X代表吸星大法，Y代表有缘相会）

 如果是后两种魔法袋，接着下一行输入怪兽等级

 输出
 参考Sample Output

 样例输入
 10
 4
 G
 B
 X
 5
 Y
 20
 样例输出
 奥特曼状态(rank=10 hp=100 damage=30 exp=0 money=100)
 ****好事成双****
 ****成功翻倍****
 奥特曼状态(rank=20 hp=200 damage=60 exp=0 money=200)
 ****祸不单行****
 ****不幸减半****
 奥特曼状态(rank=20 hp=100 damage=30 exp=0 money=100)
 怪兽状态(rank=5 hp=100 damage=10 exp=50 money=50)
 ****吸星大法****
 ****大功告成****
 奥特曼状态(rank=20 hp=150 damage=35 exp=25 money=125)
 怪兽状态(rank=20 hp=400 damage=40 exp=200 money=200)
 ****有缘相会****
 ****有缘有分****
 奥特曼状态(rank=20 hp=550 damage=75 exp=225 money=325)
 提示
 */

#include <iostream>
using namespace std;

class Monster;

class Player {
protected:
    int rank = 1;
    int exp = 0;
    int hp, damage, money;

public:
    Player();
    Player(int _rank, int _exp, int _hp, int _damage, int _money)
        : rank(_rank), exp(_exp), hp(_hp), damage(_damage), money(_money) {}
    int getRank();
    int getExp();
    int getHp();
    int getDamage();
    int getMoney();
};

//这里开始写类的界面代码
//奥特曼类的界面
class Ultraman : public Player {
public:
    Ultraman(int _rank);
    friend ostream& operator<<(ostream& cout, Ultraman& u);
    Ultraman& operator++();
    Ultraman& operator--();
    bool operator<(Monster& m);
    bool operator==(Monster& m);
};

// 怪兽类的界面
// 怪兽（Monster）
class Monster : public Player {
public:
    Monster(int rank);
    Monster(int _rank, int _damage, int _hp, int _money, int _exp)
        : Player(_rank, _exp, _hp, _damage, _money) {}
    friend ostream& operator<<(ostream& cout, Monster& m);
};

// 初始化(利用构造函数完成初始化)，参数是等级，等级与其他属性的关系：
// 生命是等级10倍，攻击是等级3倍，金钱是等级的10倍，经验开始为0。
Ultraman::Ultraman(int rank)
    : Player(rank, 0, 10 * rank, 3 * rank, 10 * rank) {}

// “好事成双”魔法袋(重载++)：使自己的等级翻倍，生命值恢复满血，为翻倍后等级的10倍，攻击力提升为翻倍后等级的3倍，经验和钱财翻倍。
Ultraman& Ultraman::operator++() {
    rank *= 2;
    hp = 10 * rank;
    damage = 3 * rank;
    exp *= 2;
    money *= 2;
    return *this;
}

// “祸不单行”魔法袋(重载––)：使自己的生命值、攻击力、经验和钱财缩减为原来的一半。
Ultraman& Ultraman::operator--() {
    hp /= 2;
    damage /= 2;
    exp /= 2;
    money /= 2;
    return *this;
}

//  “吸星大法”魔法袋(重载
//  <)：所当前所打怪兽等级小于奥特曼，则奥特曼的生命值、攻击力、经验和钱财将增加怪兽相应属性的一半。
bool Ultraman::operator<(Monster& m) {
    bool flag = m.getRank() < rank;
    if (flag) {
        hp += m.getHp() / 2;
        damage += m.getDamage() / 2;
        exp += m.getExp() / 2;
        money += m.getMoney() / 2;
    }
    return flag;
}

// “有缘相会”魔法袋(重载
// ==)：所当前所打怪兽等级等于奥特曼，则奥特曼的生命值、攻击力、经验和钱财将增加怪兽相应属性的取值。
bool Ultraman::operator==(Monster& m) {
    bool flag = m.getRank() == rank;
    if (flag) {
        hp += m.getHp();
        damage += m.getDamage();
        exp += m.getExp();
        money += m.getMoney();
    }
    return flag;
}

Monster::Monster(int rank)
    : Player(rank, 10 * rank, 20 * rank, 2 * rank, 10 * rank) {}

ostream& operator<<(ostream& cout, Ultraman& u) {
    cout << "奥特曼状态(rank=" << u.rank << " hp=" << u.hp
         << " damage=" << u.damage << " exp=" << u.exp << " money=" << u.money
         << ")" << endl;
    return cout;
}

ostream& operator<<(ostream& cout, Monster& m) {
    cout << "怪兽状态(rank=" << m.rank << " hp=" << m.hp
         << " damage=" << m.damage << " exp=" << m.exp << " money=" << m.money
         << ")" << endl;
    return cout;
}

int Player::getRank() {
    return rank;
}

int Player::getExp() {
    return exp;
}

int Player::getHp() {
    return hp;
}

int Player::getDamage() {
    return damage;
}

int Player::getMoney() {
    return money;
}

int main() {
    int ograd;

    // 输入奥特曼的等级值，利用等级值，声明一个奥特曼对象。
    cin >> ograd;

    Ultraman uobj(ograd);

    // 显示奥特曼对象初始状态
    cout << uobj;

    int t;
    // 输入测试次数
    cin >> t;

    while (t--) {
        char c = 0;

        while (1) {
            //输入要使用的魔法袋，G代表好事成双，B代表祸不单行，X代表吸星大法，Y代表有缘相会
            cin >> c;

            if (c == 'G') {
                cout << "****好事成双****" << endl;

                ++uobj;

                cout << "****成功翻倍****" << endl;

                break;

            }

            else if (c == 'B') {
                cout << "****祸不单行****" << endl;

                --uobj;

                cout << "****不幸减半****" << endl;

                break;

            }

            else if (c == 'X') {
                int r;
                //输入怪兽的等级值，利用等级值，声明一个怪兽对象并显示对象初始状态。
                cin >> r;

                Monster mobj(r);

                // mobj.display();
                cout << mobj;

                cout << "****吸星大法****" << endl;

                if (uobj < mobj)
                    cout << "****大功告成****" << endl;

                else
                    cout << "****尚未成功****" << endl;

                break;

            }

            else if (c == 'Y') {
                int r;
                //输入怪兽的等级值，利用等级值，声明一个怪兽对象并显示对象初始状态。
                cin >> r;

                Monster mobj(r);

                // mobj.display();
                cout << mobj;

                cout << "****有缘相会****" << endl;

                if (uobj == mobj)
                    cout << "****有缘有分****" << endl;

                else
                    cout << "****无缘无分****" << endl;

                break;

            }

            else
                cout << "请重新输入魔法袋类型" << endl;
        }

        cout << uobj;
    }

    return 0;
}