//
//  main.cpp
//  奥特曼打怪兽之多态（系列5）
//
//  Created by Jacky on 2020/12/1.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述

 重新组织和修改前面“类的继承”的代码，利用多态实现以下内容，使得下面的main函数能正确执行并输出相关信息。

 对怪兽类进行了扩充和修改：

 Monster类：

 1.添加lose方法，当被奥特曼打败后，输出：Boss!Help!

 2.修改display方法，以以下格式输出怪兽状态(??代表具体数值)：

 怪兽状态(rank=?? hp=?? damage=?? exp=?? money=??)

 Boss类：

 1.修改绝招(XP)方法，在原来的基础上添加代码，使得每次调用此方法时，输出：

 XP*****

 2.添加lose方法，当被奥特曼打败后，输出：

 I'll be back!

 3.修改display方法，以以下格式输出怪兽状态(??代表具体数值)：

 Boss怪兽状态(rank=?? hp=?? damage=?? exp=?? money=??)

 请自行将部分函数设置成虚函数，以实现多态。

  

 *******************************************************************************

 谁也不知道迎接奥特曼的下一个怪兽是小怪兽还是Boss。边打边看，且打且珍惜吧。
```
 int main(){

     //输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。

     int ograd;   cin>>ograd;

     Ultraman uobj(ograd);

     int t;   cin>>t;//输入要打的怪兽个数数

     while(t--&&uobj.getHp()>10){//只要奥特曼没死也没逃跑，就继续与怪兽的战斗

          uobj.display();

          Monster* p;

          char c=0;

          while(1){

              cin>>c;

              if(c=='B') {p=new Boss();break;}

              else if(c=='M') {int r;cin>>r;p=new Monster(r);break;}

              else cout<<"请重新输入怪兽类型"<<endl;

          }

          p->display();

          //设置战斗标志flag为true，启动战斗循环，具体如下：

          int flag=1;

          while(flag) //当战斗未结束就继续

          {   uobj.attack(*p);//奥特曼攻击1次

              if (p->getHp()>0)  //怪兽没死

              {   p->fightback(uobj);//怪兽反击1次

                   if (uobj.getHp()>10)      //奥特曼生命值大于点，不逃跑

                       uobj.restore();//奥特曼回血，在方法中判断是否需要加血

                   else {   //奥特曼逃跑，并输出"lose"并回车

                       uobj.escape();

                       cout<<"lose"<<endl;

                       uobj.display();//输出奥特曼状态

                       flag=0;//停止战斗

                   }

              }

              else //怪兽死了

              {   uobj.win(*p);     //奥特曼胜利，并输出"win"并回车

                   cout<<"win"<<endl;

                   uobj.upgrade();//奥特曼升级

 p->lose();//输出怪兽战败信息

                   flag=0;//停止战斗

              }

          }

     }

     return 0;

 }
```
 输入
 第1行输入奥特曼等级

 第2行输入怪兽个数

 对于每个怪兽，首先输入怪兽类别（‘M’或‘B’）

 如果是小怪兽，接着下一行输入怪兽等级

 输出
 输出战斗过程。具体参考Sample Output

 样例输入
 30
 3
 M
 5
 M
 5
 B
 样例输出
 奥特曼状态(rank=30 hp=300 damage=90 exp=0 money=300)
 怪兽状态(rank=5 hp=100 damage=10 exp=50 money=50)
 win
 Boss!Help!
 奥特曼状态(rank=30 hp=295 damage=90 exp=50 money=350)
 怪兽状态(rank=5 hp=100 damage=10 exp=50 money=50)
 win
 Boss!Help!
 奥特曼状态(rank=30 hp=290 damage=90 exp=100 money=400)
 Boss怪兽状态(rank=10 hp=300 damage=50 exp=1000 money=1001)
 win
 I'll be back!
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
    // 初始化(利用构造函数完成初始化)，参数是等级，等级与其他属性的关系：
    // 生命是等级10倍，攻击是等级3倍，金钱是等级的10倍，经验开始为0。
    bool is_escape = false;
    Ultraman(int _rank);
    void display();
    void escape();
    void attacked(Monster& m);
    void restore();
    void upgrade();
    void win(Monster& m, bool print);
};

// 怪兽类的界面
// 怪兽（Monster）
class Monster : public Player {
public:
    Monster(int rank) : Player(rank, 10 * rank, 20 * rank, 2 * rank, 10 * rank) {}
    Monster(int _rank, int _damage, int _hp, int _money, int _exp)
    :Player(_rank, _exp, _hp, _damage, _money) {}
    void attacked(Ultraman& u);
    virtual void display();
    virtual void lose();
};

class Boss : public Monster {
public:
    static int attacked_num;
    Boss() : Monster(10, 50, 300, 1001, 1000) {}
    void attacked(Ultraman& u) {
        Boss::attacked_num++;
        Monster::attacked(u);
    }
    void XP(Ultraman & u) {
        cout << "XP*****" << endl;
        Boss::attacked_num = 0;
        for (int i = 0; i < 3; i++) {
            u.attacked(*this);
        }
    }
    void lose() {
        cout << "I'll be back!" << endl;
    }
    void display() {
        printf("Boss怪兽状态(rank=%d hp=%d damage=%d exp=%d money=%d)\n",
               rank, hp, damage, exp, money);
    }
};
int Boss::attacked_num = 0;

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

// 初始化(利用构造函数完成初始化)，参数是等级，等级与其他属性的关系：
// 生命是等级10倍，攻击是等级3倍，金钱是等级的10倍，经验开始为0。
Ultraman::Ultraman(int rank) : Player(rank, 0, 10 * rank, 3 * rank, 10 * rank) {}
void Ultraman::display() {
    printf("奥特曼状态(rank=%d hp=%d damage=%d exp=%d money=%d)\n",
           rank, hp, damage, exp, money);
}
void Ultraman::escape() {
    money = 0;
    is_escape = true;
    cout << "lose" << endl;
}

void Ultraman::attacked(Monster& m) {
    // 当怪兽反击时，奥特曼受到的伤害等于怪兽攻击力的一半，
    // 即生命损失=怪兽攻击力值/2，取整处理
    hp -= m.getDamage() / 2;
}

void Ultraman::restore() {
    // 生命低于50%但大于10点（大于10点已在main里判断）
    // 生命值上限(等级的10倍)。
    while (hp < 5 * rank && money >= 10) {
        hp++;
        money -= 10;
    }
}

void Ultraman::upgrade() {
    //达到升级条件可以升级，
    //条件是经验值不小于等级10倍。升级将扣除相应的经验值，生命满血，更新生命上限和攻击力
    while (exp >= 10 * rank) {
        exp -= 10 * rank;
        rank++;
        hp = rank * 10;
        damage = rank * 3;
    }
}

void Ultraman::win(Monster& m, bool print = true) {
    if (m.getHp() <= 0) {
        money += m.getMoney();
        exp += m.getExp();
        if (print) {
            cout << "win" << endl;
        }
    }
}

// -------------------------------------------------------------
void Monster::display() {
    printf("怪兽状态(rank=%d hp=%d damage=%d exp=%d money=%d)\n",
           rank, hp, damage, exp, money);
}

void Monster::attacked(Ultraman& u) {
    // 当奥特曼攻击时，怪兽受到的伤害等于奥特曼攻击力，即生命损失=奥特曼攻击力值
    hp -= u.getDamage();
}

void Monster::lose() {
    cout << "Boss!Help!" << endl;
}

int main(){
    
    //输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。
    
    int ograd;
    cin >> ograd;
    
    Ultraman uobj(ograd);
    
    int t;
    cin >> t;//输入要打的怪兽个数数
    while(t--&&uobj.getHp()>10){//只要奥特曼没死也没逃跑，就继续与怪兽的战斗
        uobj.display();
        Monster* p;
        char c=0;
        while(1){
            cin>>c;
            if(c=='B') {p=new Boss();break;}
            else if(c=='M') {int r;cin>>r;p=new Monster(r);break;}
            else cout<<"请重新输入怪兽类型"<<endl;
        }
        
        p->display();
        
        //设置战斗标志flag为true，启动战斗循环，具体如下：
        int flag=1;
        
        while(flag) //当战斗未结束就继续
        {
            //uobj.attack(*p);//奥特曼攻击1次
            p->attacked(uobj);
            if (p->getHp()>0)  //怪兽没死
            {
                //p->fightback(uobj);//怪兽反击1次
                uobj.attacked(*p);
                if (uobj.getHp()>10)      //奥特曼生命值大于点，不逃跑
                    uobj.restore();//奥特曼回血，在方法中判断是否需要加血
                else {   //奥特曼逃跑，并输出"lose"并回车
                    uobj.escape();
                    //cout<<"lose"<<endl;
                    uobj.display();//输出奥特曼状态
                    flag=0;//停止战斗
                }
            }
            else //怪兽死了
            {
                uobj.win(*p);     //奥特曼胜利，并输出"win"并回车
                //cout<<"win"<<endl;
                uobj.upgrade();//奥特曼升级
                p->lose();//输出怪兽战败信息
                flag=0;//停止战斗
            }
        }
    }
    return 0;
}
