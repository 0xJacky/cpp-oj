//
//  main.cpp
//  奥特曼打怪兽之类的继承（系列4）
//
//  Created by Jacky on 2020/11/17.
//  Copyright © 2020 Jacky. All rights reserved.
//

/*
 题目描述
 重新组织和修改前面“类的实现”的代码，利用继承实现以下内容。
 
 奥特曼在与多个小怪兽过招的过程中，不断提升自己的等级。在一切就绪的时候，就可以挑战小怪兽的头Boss了。打败Boss就可以获得最终的胜利。
 
 在怪兽类的基础上，定义和实现一个子类Boss类。如有必要，请对奥特曼和怪兽类做出相应的修改。
 
 Boss类对怪兽类进行了扩充和修改：
 
 l  Boss属性的初始值与一般怪兽不同，等级为10，生命值为300，经验值是1000，攻击力是50，钱数是1001。
 
 l  Boss有一个新的方法，即绝招(XP)。该方法将连续攻击奥特曼3次。
 
 l  Boss的反击方法(fightback)也与一般怪兽不同，一般情况下受到奥特曼的攻击就会反击一次，但每当Boss受到奥特曼攻击的次数(count)累计5次，就会使用绝招(XP)。
 
 
 
 *******************************************************************************
 
 Outman（奥特曼类对象）在打败所有的小怪兽后，将挑战怪兽之王。
 
 请在main函数中实现如下架构
 
 int main(){
 
 //输入测试次数
 
 
 
 while(t--){
 
 //输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。
 
 //输入怪兽个数和等级
 
 
 
 while(？？？？)//只要奥特曼没死也没逃跑，就继续与n个怪兽的战斗
 
 {
 
 利用怪兽等级值生成怪兽对象
 
 
 
 //设置战斗标志flag为true，启动战斗循环，具体如下：
 
 while(flag) //当战斗未结束就继续
 
 {
 
 //奥特曼攻击1次
 
 if (？？？？)  //怪兽没死
 
 {   //怪兽反击1次
 
 
 
 if (？？？)       //奥特曼没死也不逃跑
 
 //奥特曼回血，在方法中判断是否需要加血
 
 
 
 else
 
 {   //奥特曼逃跑，并输出"lose"并回车
 
 
 
 //输出奥特曼状态，调用display方法
 
 
 
 //设置flag为false，停止战斗
 
 
 
 }
 
 }
 
 else //怪兽死了
 
 {
 
 //奥特曼胜利，并输出"win"并回车
 
 
 
 //奥特曼升级
 
 
 
 //设置flag为false，停止战斗
 
 
 
 }
 
 }
 
 }
 
 
 
 if(？？？？)//如果打完n个小怪兽奥特曼还没死也没逃跑，就挑战Boss
 
 {
 
 //输出奥特曼当前状态
 
 
 
 //生成Boss对象初始化
 
 
 
 
 
 //设置战斗标志flag为true，启动战斗循环，具体如下：
 
 
 
 while(flag) //当战斗未结束就继续
 
 {
 
 //奥特曼攻击1次
 
 
 
 if (？？？？)  //Boss没死
 
 {   //Boss反击1次
 
 
 
 if (？？？)       //奥特曼没死也不逃跑
 
 //奥特曼回血，在方法中判断是否需要加血
 
 
 
 else
 
 {   //奥特曼逃跑，并输出"lose"并回车
 
 
 
 //输出奥特曼状态，调用display方法
 
 
 
 //设置flag为false，停止战斗
 
 
 
 }
 
 }
 
 
 
 else //怪兽死了
 
 {
 
 //奥特曼胜利，并输出"win Boss"并回车
 
 
 
 //奥特曼升级
 
 
 
 //输出奥特曼状态，调用display方法
 
 
 
 //设置flag为false，停止战斗
 
 
 
 }
 
 }
 
 }
 
 }
 
 return 0;
 
 }
 
 
 输入
 第1行输入t表示有t个测试实例
 
 对于每个测试实例，首行先输入奥特曼等级
 
 接着下一行输入n和k，表示怪兽数量和等级
 
 输出
 输出每个测试实例的战斗结果。
 
 对于每一个实例的输出如下：
 
 第一行奥特曼的状态
 
 第二行~第n+1行依次输出奥特曼打每个怪兽的结果。
 
 如果奥特曼把n个怪兽都打败了，
 
 第n+2行输出此时奥特曼的状态
 
 第n+3行输出奥特曼打怪兽首领的结果
 
 第n+4行输出奥特曼打怪兽首领后的状态
 
 
 
 如果奥特曼被某个怪兽打败，则输出战斗结果，下一行输出战斗后奥特曼的状态，不再与怪兽首领进行战斗。
 
 样例输入
 2
 5
 5 5
 20
 5 10
 样例输出
 奥特曼状态(rank=5 hp=50 damage=15 exp=0 money=50)
 win
 win
 win
 win
 win
 奥特曼状态(rank=8 hp=60 damage=24 exp=70 money=150)
 lose
 奥特曼状态(rank=8 hp=0 damage=24 exp=70 money=0)
 奥特曼状态(rank=20 hp=200 damage=60 exp=0 money=200)
 win
 win
 win
 win
 win
 奥特曼状态(rank=22 hp=220 damage=66 exp=90 money=700)
 win Boss
 奥特曼状态(rank=26 hp=260 damage=78 exp=150 money=1701)
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
    Monster(int rank)
        : Player(rank, 10 * rank, 20 * rank, 2 * rank, 10 * rank) {}
    Monster(int _rank, int _damage, int _hp, int _money, int _exp)
        : Player(_rank, _exp, _hp, _damage, _money) {}
    void attacked(Ultraman& u);
    void display();
};

class Boss : public Monster {
public:
    static int attacked_num;
    Boss() : Monster(10, 50, 300, 1001, 1000) {}
    void attacked(Ultraman& u) {
        Boss::attacked_num++;
        Monster::attacked(u);
    }
    void XP(Ultraman& u) {
        Boss::attacked_num = 0;
        for (int i = 0; i < 3; i++) {
            u.attacked(*this);
        }
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
Ultraman::Ultraman(int rank)
    : Player(rank, 0, 10 * rank, 3 * rank, 10 * rank) {}
void Ultraman::display() {
    printf("奥特曼状态(rank=%d hp=%d damage=%d exp=%d money=%d)\n", rank, hp,
           damage, exp, money);
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
    printf("rank=%d hp=%d damage=%d exp=%d money=%d\n", rank, hp, damage, exp,
           money);
}

void Monster::attacked(Ultraman& u) {
    // 当奥特曼攻击时，怪兽受到的伤害等于奥特曼攻击力，即生命损失=奥特曼攻击力值
    hp -= u.getDamage();
}

int main() {
    int t;
    //输入测试次数
    cin >> t;
    while (t--) {
        int u_rank, m_num, m_rank;
        //输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。
        cin >> u_rank;
        Ultraman u(u_rank);
        u.display();
        //输入怪兽个数和等级
        cin >> m_num >> m_rank;

        while (!u.is_escape && u.getHp() > 0 &&
               m_num--)  //只要奥特曼没死也没逃跑，就继续与n个怪兽的战斗
        {
            //利用怪兽等级值生成怪兽对象
            Monster m(m_rank);
            //设置战斗标志flag为true，启动战斗循环，具体如下：
            bool flag = true;
            while (flag)  //当战斗未结束就继续
            {
                //奥特曼攻击1次
                m.attacked(u);
                if (m.getHp() > 0)  //怪兽没死
                {
                    //怪兽反击1次
                    u.attacked(m);
                    if (u.getHp() >= 10) {  //奥特曼没死也不逃跑
                        //奥特曼回血，在方法中判断是否需要加血
                        u.restore();
                    } else {
                        //奥特曼逃跑，并输出"lose"并回车
                        u.escape();
                        //输出奥特曼状态，调用display方法
                        u.display();
                        //设置flag为false，停止战斗
                        flag = false;
                    }
                } else {
                    //怪兽死了
                    //奥特曼胜利，并输出"win"并回车
                    u.win(m);
                    u.upgrade();
                    //设置flag为false，停止战斗
                    flag = false;
                }
            }
        }

        if (!u.is_escape &&
            u.getHp() > 0)  //如果打完n个小怪兽奥特曼还没死也没逃跑，就挑战Boss
        {
            //输出奥特曼当前状态
            u.display();
            //生成Boss对象初始化
            Boss b;
            //设置战斗标志flag为true，启动战斗循环，具体如下：
            bool flag = true;
            Boss::attacked_num = 0;
            while (flag)  //当战斗未结束就继续
            {
                //奥特曼攻击1次
                b.attacked(u);
                if (b.getHp() > 0)  //Boss没死
                {
                    if (Boss::attacked_num == 5) {
                        b.XP(u);
                    } else {
                        //Boss反击1次
                        u.attacked(b);
                    }

                    if (u.getHp() >= 10) {
                        //奥特曼没死也不逃跑
                        //奥特曼回血，在方法中判断是否需要加血
                        u.restore();
                    } else {
                        //奥特曼逃跑，并输出"lose"并回车
                        u.escape();
                        //输出奥特曼状态，调用display方法
                        u.display();
                        //设置flag为false，停止战斗
                        flag = false;
                    }
                } else {
                    //奥特曼胜利，并输出"win Boss"并回车
                    cout << "win Boss" << endl;
                    u.win(b, false);
                    //奥特曼升级
                    u.upgrade();
                    //输出奥特曼状态，调用display方法
                    u.display();
                    //设置flag为false，停止战斗
                    flag = false;
                }
            }
        }
    }
    return 0;
}