 # 奥特曼打怪兽之类的应用（系列3）
 ## 题目描述
 在前面实验的基础上，根据题目要求进行修改，实现打斗过程。
 
 1.      怪兽分为四种类型(定义四个类)：
 
 普通型怪兽（NMonster）：攻击力是等级2倍，生命是10倍，金钱经验是10倍
 
 攻击型怪兽（AMonster）：攻击力是等级4倍，生命是5倍，金钱经验是10倍
 
 防御型怪兽（DMonster）：攻击力是等级1倍，生命是20倍，金钱经验是10倍
 
 肉鸡型怪兽（SMonster）：攻击力是等级1倍，生命是10倍，金钱经验是20倍
 
 2.      定义一个守护神类（Angel），该类定义怪兽或奥特曼的守护神，为怪兽或奥特曼提供帮助。守护神等级为所守护对象的等级（例如守护神a1守护等级为3的攻击型怪兽am1，则a1的等级也为3），攻击是等级的一半，无生命。怪兽的守护神金钱和经验都为等级的5倍。奥特曼的守护神金钱和经验为0，等级随守护对象升级而升级。
 
 3.      为四个怪兽类和奥特曼类添加守护神对象成员，使它们都成为复合类。
 
 4.      当奥特曼战胜怪兽后，将获得怪兽及其守护神的经验金钱。
 
 5.      修改奥特曼类和怪兽类相关成员函数，实现守护神类与它们的关系，具体如下：
 
 奥特曼，守护神为它攻击攻击型怪兽时，加1点攻击力，而在它攻击防御型怪兽时，加2点攻击力，在获得肉鸡型怪兽的金钱和经验时，翻倍(获得怪兽的经验和金钱翻倍)。
 
 普通型怪兽和肉鸡型怪兽，无守护神。
 
 攻击型怪兽，守护神为它在攻击奥特曼时，也打一次，使奥特曼除了受到怪兽攻击，还将将受到守护神攻击力的伤害。
 
 防御型怪兽，守护神为它受到奥特曼攻击时，将生命损失减半。
 
 
 
 
 
 *******************************************************************************
 
 outman（奥特曼类对象）这个热血骚年总是叫嚷“一个打十个”，叫的老天爷都不耐烦了。这次outman傻眼了，是一个打4个。现在让我们来为outman欢呼吧，围观吧（记得带上板凳瓜子和鸡蛋，不好看的话就扔扔）。
 
 请在main函数中实现如下架构
 
 while (t--)  //每个实例就是奥特曼与个怪兽的战斗
 
 {
 
 //输入奥特曼等级值，利用等级值，声明一个奥特曼对象并初始化。
 
 //输出奥特曼状态，调用display方法，每行输出一个
 
 //输入个怪兽的等级，依次为普通型怪兽、肉鸡型怪兽、防御型怪兽、攻击型怪兽，保存在数组mgrad[4]中
 
 //创建种类型怪兽对象并利用等级值mgrad初始化。
 
 //输出每个怪兽的状态，调用display方法，每行输出一个
 
 //设置战斗标志flag为true，与每个怪兽的战斗结果winflag1=0,winflag2=0,winflag3=0,winflag4=0。
 
 //启动战斗循环，具体如下：
 
 while(flag) //4个怪兽群殴奥特曼
 
 {
 
 
 //奥特曼攻击每个怪兽1次
 
 
 
 
 if (如果怪兽i没死)  //如果怪兽i没死，怪兽i攻击奥特曼，注意：只要没死的怪兽，都攻击奥特曼次。
 
 {
 
 //怪兽i反击1次
 
 
 
 if (奥特曼不逃跑)     //如果奥特曼不逃跑，用奥特曼生命来判断
 
 //奥特曼回血，在方法中判断是否需要加血
 
 else
 
 {   //奥特曼逃跑，设置逃跑标志eflag为true，并输出"lose"并回车
 
 //输出奥特曼状态，调用display方法
 
 //设置flag为false，停止战斗
 
 }
 
 }
 
 else if(怪兽是这一轮死的)//如果怪兽这一轮死了
 
 {
 
 //奥特曼胜利，并输出"win"并回车
 
 //奥特曼升级
 
 //输出奥特曼状态，调用display方法
 
 //设置打赢标记winflagi为true
 
 }
 
 if(所有怪兽都死了){//所有怪兽都死了，用个打赢标记判断
 
 //结束战斗，设置flag为false，并输出“win all”
 
 }
 
 }//end of while flag
 
 
 ## 输入
 第1行输入t表示有t个测试实例
 
 
 
 对于每个测试实例，首行先输入奥特曼等级
 
 
 
 接着4行依次输入普通型、肉鸡型、防御型、攻击型怪兽的等级
 
 ## 输出
 输出奥特曼和每个怪兽的战斗结果，具体要求参考程序框架
 
 ## 样例输入
 2
 5
 3
 3
 3
 3
 5
 10
 10
 10
 10
 ## 样例输出
 rank=5 hp=50 damage=15 exp=0 money=50
 rank=3 hp=30 damage=6 exp=30 money=30
 rank=3 hp=30 damage=3 exp=60 money=60
 rank=3 hp=60 damage=3 exp=30 money=30
 rank=3 hp=15 damage=12 exp=30 money=30
 win
 rank=5 hp=45 damage=15 exp=45 money=95
 win
 rank=6 hp=60 damage=18 exp=25 money=125
 win
 rank=8 hp=80 damage=24 exp=15 money=245
 win
 rank=8 hp=76 damage=24 exp=60 money=290
 win all
 rank=5 hp=50 damage=15 exp=0 money=50
 rank=10 hp=100 damage=20 exp=100 money=100
 rank=10 hp=100 damage=10 exp=200 money=200
 rank=10 hp=200 damage=10 exp=100 money=100
 rank=10 hp=50 damage=40 exp=100 money=100
 lose
 rank=5 hp=8 damage=15 exp=0 money=0
 ## 提示
 */

#include <iostream>
using namespace std;
class NMonster;
class AMonster;
class DMonster;
class SMonster;
class Angel;

//这里开始写类的界面代码
//奥特曼类的界面
class Ultraman {
private:
    int rank = 1;
    int exp = 0;
    int hp, damage, money;
    
public:
    // 初始化(利用构造函数完成初始化)，参数是等级，等级与其他属性的关系：
    // 生命是等级10倍，攻击是等级3倍，金钱是等级的10倍，经验开始为0。
    Ultraman(int _rank);
    void display();
    void escape();
    void attacked(NMonster& m);
    void attacked(AMonster& m, Angel& a);
    void attacked(DMonster& m, Angel& a);
    void attacked(SMonster& m);
    void restore();
    void upgrade();
    void win(NMonster& m);
    void win(AMonster& m, Angel& a);
    void win(DMonster& m, Angel& a);
    void win(SMonster& m);
    int getRank();
    int getExp();
    int getHp();
    int getDamage();
    int getMoney();
};

// 怪兽类的界面
// 怪兽（Monster）
class Monster {
protected:
    int rank = 1;
    int exp = 0;
    int hp, damage, money;
    
public:
    Monster(int _rank,  int _damage, int _hp, int _money, int _exp) :
    rank(_rank), hp(_hp), damage(_damage),
    money(_money), exp(_exp) {}
    void display();
    int getRank();
    int getExp();
    int getHp();
    int getDamage();
    int getMoney();
};

// 普通型怪兽类的界面
// 普通型怪兽（NMonster）：攻击力是等级2倍，生命是10倍，金钱经验是10倍
class NMonster: public Monster {
public:
    NMonster(int rank): Monster(rank, 2* rank, 10* rank,  10 * rank, 10 * rank) {}
    void attacked(Ultraman& u, Angel& a);
};

//攻击型怪兽的界面
class AMonster: public Monster {
public:
    //攻击型怪兽（AMonster）：攻击力是等级4倍，生命是5倍，金钱经验是10倍
    AMonster(int rank): Monster(rank, 4 * rank, 5 * rank,  10 * rank, 10 * rank) {}
    void attacked(Ultraman& u, Angel& a);
};

//防御型怪兽类的界面
class DMonster: public Monster {
public:
    // 防御型怪兽（DMonster）：攻击力是等级1倍，生命是20倍，金钱经验是10倍
    DMonster(int rank): Monster(rank, rank, 20 * rank, 10 * rank, 10 * rank) {}
    void attacked(Ultraman& u, Angel& a);
};

//肉鸡型怪兽类的界面
class SMonster: public Monster {
public:
    // 肉鸡型怪兽（SMonster）：攻击力是等级1倍，生命是10倍，金钱经验是20倍
    SMonster(int rank): Monster(rank, rank, 10 * rank, 20 * rank, 20 * rank) {}
    void attacked(Ultraman& u, Angel& a);
};

// 守护神类
class Angel {
public:
    // 定义一个守护神类（Angel），该类定义怪兽或奥特曼的守护神，为怪兽或奥特曼提供帮助。守护神等级为所守护对象的等级（例如守护神a1守护等级为3的攻击型怪兽am1，则a1的等级也为3），攻击是等级的一半，无生命。怪兽的守护神金钱和经验都为等级的5倍。奥特曼的守护神金钱和经验为0，等级随守护对象升级而升级。
    // 普通型怪兽和肉鸡型怪兽，无守护神。
    Angel(Ultraman& u) :rank(u.getRank()), exp(0), money(0), damage(rank / 2) {}
    Angel(AMonster& u) :rank(u.getRank()), exp(5 * rank), money(exp), damage(rank / 2) {}
    Angel(DMonster& u) :rank(u.getRank()), exp(5 * rank), money(exp), damage(rank / 2) {}
    int getMoney() {
        return money;
    }
    int getExp() {
        return exp;
    }
    int getDamage() {
        return damage;
    }
private:
    int rank;
    int exp;
    int money;
    int damage;
};
// 初始化(利用构造函数完成初始化)，参数是等级，等级与其他属性的关系：
// 生命是等级10倍，攻击是等级3倍，金钱是等级的10倍，经验开始为0。
Ultraman::Ultraman(int _rank) :
rank(_rank), hp(10 * rank), damage(3 * rank), money(10 * rank) {
}
void Ultraman::display() {
    printf("rank=%d hp=%d damage=%d exp=%d money=%d\n",
           rank, hp, damage, exp, money);
}
void Ultraman::escape() {
    money = 0;
    cout << "lose" << endl;
}

//普通型怪兽和肉鸡型怪兽，无守护神。
void Ultraman::attacked(NMonster& m) {
    // 当怪兽反击时，奥特曼受到的伤害等于怪兽攻击力的一半，
    // 即生命损失=怪兽攻击力值/2，取整处理
    hp -= m.getDamage() / 2;
}

//攻击型怪兽，守护神为它在攻击奥特曼时，也打一次，
// 使奥特曼除了受到怪兽攻击，还将将受到守护神攻击力的伤害。

void Ultraman::attacked(AMonster& m, Angel& a) {
    // 当怪兽反击时，奥特曼受到的伤害等于怪兽攻击力的一半，
    // 即生命损失=怪兽攻击力值/2，取整处理
    hp -= (m.getDamage() + a.getDamage()) / 2;
}

// 防御型怪兽，守护神为它受到奥特曼攻击时，将生命损失减半。
void Ultraman::attacked(DMonster& m, Angel& a) {
    // 当怪兽反击时，奥特曼受到的伤害等于怪兽攻击力的一半，
    // 即生命损失=怪兽攻击力值/2，取整处理
    hp -= m.getDamage() / 2;
}

//普通型怪兽和肉鸡型怪兽，无守护神。
void Ultraman::attacked(SMonster& m) {
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

void Ultraman::win(NMonster& m) {
    if (m.getHp() <= 0) {
        money += m.getMoney();
        exp += m.getExp();
        cout << "win" << endl;
    }
}

void Ultraman::win(AMonster& m, Angel& a) {
    if (m.getHp() <= 0) {
        money += m.getMoney();
        money += a.getMoney();
        exp += m.getExp();
        exp += a.getExp();
        cout << "win" << endl;
    }
}
void Ultraman::win(DMonster& m, Angel& a) {
    if (m.getHp() <= 0) {
        money += m.getMoney();
        money += a.getMoney();
        exp += m.getExp();
        exp += a.getExp();
        cout << "win" << endl;
    }
}
void Ultraman::win(SMonster& m) {
    // 在获得肉鸡型怪兽的金钱和经验时，翻倍(获得怪兽的经验和金钱翻倍)。
    if (m.getHp() <= 0) {
        money += 2 * m.getMoney();
        exp += 2 * m.getExp();
        cout << "win" << endl;
    }
}

int Ultraman::getRank() {
    return rank;
}

int Ultraman::getExp() {
    return exp;
}

int Ultraman::getHp() {
    return hp;
}

int Ultraman::getDamage() {
    return damage;
}

int Ultraman::getMoney() {
    return money;
}

// -------------------------------------------------------------
void Monster::display() {
    printf("rank=%d hp=%d damage=%d exp=%d money=%d\n",
           rank, hp, damage, exp, money);
}

int Monster::getRank() {
    return rank;
}

int Monster::getExp() {
    return exp;
}

int Monster::getHp() {
    return hp;
}

int Monster::getDamage() {
    return damage;
}

int Monster::getMoney() {
    return money;
}
// -------------------------------------------------------------
void NMonster::attacked(Ultraman& u, Angel& a) {
    hp -= a.getDamage();
    // 当奥特曼攻击时，怪兽受到的伤害等于奥特曼攻击力，即生命损失=奥特曼攻击力值
    hp -= u.getDamage();
}

// -------------------------------------------------------------
void AMonster::attacked(Ultraman& u, Angel& a) {
    hp -= a.getDamage();
    hp -= (u.getDamage() + 1);
}
// -------------------------------------------------------------
void DMonster::attacked(Ultraman& u, Angel& a) {
    // 防御型怪兽，守护神为它受到奥特曼攻击时，将生命损失减半。
    // 而在它攻击防御型怪兽时，加2点攻击力，
    //hp -= a.getDamage();
    hp -= (u.getDamage() + 2) / 2;
}
// -------------------------------------------------------------
void SMonster::attacked(Ultraman& u, Angel& a) {
    hp -= a.getDamage();
    // 当奥特曼攻击时，怪兽受到的伤害等于奥特曼攻击力，即生命损失=奥特曼攻击力值
    hp -= u.getDamage();
}
// -------------------------------------------------------------

int main()
{
    int t;
    cin >> t;   //表示有t个测试实例
    int i = 0, j = 0, k = 0, l = 0;     //判断怪兽是否本回合死亡
    // 每个实例就是奥特曼与怪兽的1对1战斗
    while (t--) {
        //1. 输入奥特曼和怪兽的等级，并调用初始化方法进行对象初始化
        int u_rank;
        cin >> u_rank;
        //2. 输出奥特曼，调用display方法，每行输出一个
        Ultraman u(u_rank);
        u.display();
        //输入个怪兽的等级，依次为普通型怪兽、肉鸡型怪兽、防御型怪兽、攻击型怪兽，保存在数组mgrad[4]中
        int mgrad[4];
        for (int i = 0; i < 4; i++) {
            cin >> mgrad[i];
        }
        //创建种类型怪兽对象并利用等级值mgrad初始化。
        NMonster nm(mgrad[0]);
        AMonster am(mgrad[1]);
        DMonster dm(mgrad[2]);
        SMonster sm(mgrad[3]);
        // 输出每个怪兽的状态，调用display方法，每行输出一个
        nm.display();
        sm.display();
        dm.display();
        am.display();
        // 为四个怪兽类和奥特曼类添加守护神对象成员，使它们都成为复合类。
        Angel u1(u);
        Angel a1(am);
        Angel d1(dm);
        
        //设置战斗标志flag为true，与每个怪兽的战斗结果winflag1=0,winflag2=0,winflag3=0,winflag4=0。
        bool flag = true, winflag1 = 0, winflag2 = 0, winflag3 = 0, winflag4 = 0, eflag = 0;
        //启动战斗循环，具体如下：
        while (flag) //4个怪兽群殴奥特曼
        {
            //奥特曼攻击每个怪兽1次
            nm.attacked(u, u1);
            sm.attacked(u, u1);
            dm.attacked(u, u1);
            am.attacked(u, u1);
            //如果普通怪兽没死，怪兽i攻击奥特曼，注意：只要没死的怪兽，都攻击奥特曼1次。
            if (nm.getHp() > 0) {
                //怪兽反击1次，或者是奥特曼被攻击1次
                u.attacked(nm);
                /*奥特曼不必逃跑*/
                //用奥特曼生命来判断，用get方法啦
                if (u.getHp() > 10) {
                    //奥特曼回血，在方法中判断是否需要加血
                    u.restore();
                }
                else {
                    //奥特曼逃跑，设置逃跑标志eflag为true，并输出"lose"并回车
                    u.escape();
                    eflag = true;
                    //输出奥特曼状态，调用display方法
                    u.display();
                    //设置flag为false，停止战斗
                    flag = false;
                }
            }
            else if (i == 0)
            {
                //奥特曼胜利，并输出"win"并回车
                u.win(nm);
                //cout << "i" << endl;
                u.upgrade();
                u1 = Angel(u);
                //输出奥特曼状态，调用display方法
                u.display();
                //设置打赢标记winflagi为true
                winflag1 = true;
                i = 1;
            }
            
            //如果肉鸡型怪兽没死，怪兽i攻击奥特曼，注意：只要没死的怪兽，都攻击奥特曼1次。
            if (sm.getHp() > 0) {
                //怪兽反击1次，或者是奥特曼被攻击1次
                u.attacked(sm);
                /*奥特曼不必逃跑*/
                //用奥特曼生命来判断，用get方法啦
                if (u.getHp() > 10) {
                    //奥特曼回血，在方法中判断是否需要加血
                    u.restore();
                }
                else {
                    //奥特曼逃跑，设置逃跑标志eflag为true，并输出"lose"并回车
                    u.escape();
                    eflag = true;
                    //输出奥特曼状态，调用display方法
                    u.display();
                    //设置flag为false，停止战斗
                    flag = false;
                }
            }
            else if (j == 0)
            {
                //奥特曼胜利，并输出"win"并回车
                u.win(sm);
                //cout << "j" << endl;
                u.upgrade();
                u1 = Angel(u);;
                //输出奥特曼状态，调用display方法
                u.display();
                //设置打赢标记winflagi为true
                winflag2 = true;
                j = 1;
            }
            
            //如果防御性怪兽没死，怪兽i攻击奥特曼，注意：只要没死的怪兽，都攻击奥特曼1次。
            if (dm.getHp() > 0) {
                //怪兽反击1次，或者是奥特曼被攻击1次
                u.attacked(dm, d1);
                /*奥特曼不必逃跑*/
                //用奥特曼生命来判断，用get方法啦
                if (u.getHp() > 10) {
                    //奥特曼回血，在方法中判断是否需要加血
                    u.restore();
                }
                else {
                    //奥特曼逃跑，设置逃跑标志eflag为true，并输出"lose"并回车
                    u.escape();
                    eflag = true;
                    //输出奥特曼状态，调用display方法
                    u.display();
                    //设置flag为false，停止战斗
                    flag = false;
                }
            }
            else if (k == 0)
            {
                //奥特曼胜利，并输出"win"并回车
                // 当奥特曼战胜怪兽后，将获得怪兽及其守护神的经验金钱。
                u.win(dm, d1);
                //cout << "k" << endl;
                u.upgrade();
                u1 = Angel(u);
                //输出奥特曼状态，调用display方法
                u.display();
                //设置打赢标记winflagi为true
                winflag3 = true;
                k = 1;
            }
            
            //如果攻击型怪兽没死，怪兽i攻击奥特曼，注意：只要没死的怪兽，都攻击奥特曼1次。
            if (am.getHp() > 0) {
                //怪兽反击1次，或者是奥特曼被攻击1次
                u.attacked(am, a1);
                /*奥特曼不必逃跑
