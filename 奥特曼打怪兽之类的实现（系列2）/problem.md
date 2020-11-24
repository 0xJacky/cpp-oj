 # 奥特曼打怪兽之类的实现（系列2）
 ## 题目描述
 在实验《类定义》的基础，改进并实现游戏中的两个类：奥特曼类和怪兽类。使得两个类更加接近实际要求。
 
 奥特曼说明如下：
 
 1.  为每个属性设置get方法，注意奥特曼所有属性都是整型。
 
 2.  初始化(利用构造函数完成初始化)，参数是等级，等级与其他属性的关系：生命是等级10倍，攻击是等级3倍，金钱是等级的10倍，经验开始为0。
 
 3. 逃跑(escape)，当生命不超过10点时，奥特曼将逃跑，逃跑将损失所有金钱，战斗结果为奥特曼失败（lose）
 
 4. 攻击（attack），（这个方法要参数么？？），当攻击怪兽时，怪兽受到的伤害等于奥特曼攻击力。（本方法实际上就是怪兽被攻击，所以不一定需要实现）
 
 5. 被攻击（attacked），（这个方法要参数么？？），当怪兽反击时，奥特曼受到的伤害等于怪兽攻击力的一半，即生命损失=怪兽攻击力值/2，取整处理
 
 6.  恢复生命(restore)，如果体力不支（生命低于50%但大于10点），每10个金钱可恢复1点生命值。只要有足够的钱，可以一直恢复，直到达到生命值上限(等级的10倍)。
 
 7. 胜利（win），（这个方法要参数么？？），当怪兽生命小于等于0，战斗结果为奥特曼胜利（win），奥特曼将获得怪兽身上所有金钱和经验值。
 
 8. 升级（upgrade）,战斗结束后，达到升级条件可以升级，条件是经验值不小于等级10倍。升级将扣除相应的经验值，生命满血，更新生命上限和攻击力。
 
 9. 显示状态（display），单行输出，格式如下：
 
 rank=等级 hp=生命 damage=攻击 exp=经验 money=金钱
 
 
 
 怪兽说明如下：
 
 1.  为每个属性设置get方法。
 
 2.  初始化（利用构造函数完成初始化），参数是等级，等级与其他属性的关系：生命是等级20倍，攻击是等级2倍，金钱是等级的10倍，经验值是等级的10倍。
 
 3. 被攻击（attacked），（这个方法要参数么？？），当奥特曼攻击时，怪兽受到的伤害等于奥特曼攻击力，即生命损失=奥特曼攻击力值
 
 4. 反击（fightback）当怪兽被反击后，如果怪兽不死，将进行反击（本方法实际上就是奥特曼被攻击，所以不一定需要实现）
 
 5. 显示状态（display），单行输出，格式如下：
 
 rank=等级 hp=生命 damage=攻击 exp=经验 money=金钱
 
 
 
 ****************************************************************************************
 
 请在main函数中实现奥特曼与怪兽的“对抽”，即1对1的战斗过程，具体步骤如下：
 
 cin>>t;   //表示有t个测试实例
 
 
 
 while (t--)  //每个实例就是奥特曼与怪兽的1对1战斗
 
 {
 
 
 
 1. 输入奥特曼和怪兽的等级，并调用初始化方法进行对象初始化
 
 2. 输出奥特曼和怪兽状态，调用display方法，每行输出一个
 
 3. 设置战斗标志flag为true，启动战斗循环，具体如下：
 
 while(flag) //当战斗未结束就继续
 
 {     //奥特曼攻击1次，或者是怪兽被攻击1次
 
 if (怪兽没死)  //用怪兽生命来判断，用get方法啦
 
 {     //怪兽反击1次，或者是奥特曼被攻击1次
 
 if (奥特曼不必逃跑)           //用奥特曼生命来判断，用get方法啦
 
 //奥特曼回血，在方法中判断是否需要加血
 
 else
 
 {     //奥特曼逃跑，并输出"lose"并回车
 
 //输出奥特曼状态，调用display方法
 
 //设置flag为false，停止战斗
 
 }
 
 }
 
 else //怪兽死了
 
 {     //奥特曼胜利，并输出"win"并回车
 
 //输出奥特曼状态，调用display方法
 
 //设置flag为false，停止战斗
 
 }
 
 }
 
 }
 
 ## 输入
 第一行先输入t表示有t个测试实例
 
 
 
 接着t行输入奥特曼和怪兽的等级
 
 ## 输出
 根据题目要求，每个实例输出4行结果：
 
 头两行是奥特曼和怪兽的初始状态
 
 第3行是战斗结果
 
 第4行是奥特曼的最终状态
 
 
 ## 样例输入
 2
 5 5
 5 10
 ## 样例输出
 rank=5 hp=50 damage=15 exp=0 money=50
 rank=5 hp=100 damage=10 exp=50 money=50
 win
 rank=6 hp=60 damage=18 exp=0 money=50
 rank=5 hp=50 damage=15 exp=0 money=50
 rank=10 hp=200 damage=20 exp=100 money=100
 lose
 rank=5 hp=5 damage=15 exp=0 money=0
 */
#include <iostream>
using namespace std;
class Monster;

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
    void attacked(Monster& m);
    void restore();
    void upgrade();
    void win(Monster& m);
    int getRank();
    int getExp();
    int getHp();
    int getDamage();
    int getMoney();
};

//怪兽类的界面
class Monster {
private:
    int rank = 1;
    int exp = 0;
    int hp, damage, money;
    
public:
    // 初始化（利用构造函数完成初始化），参数是等级，等级与其他属性的关系：
    // 生命是等级20倍，攻击是等级2倍，金钱是等级的10倍，经验值是等级的10倍。
    Monster(int _rank);
    void display();
    void attacked(Ultraman& u);
    int getRank();
    int getExp();
    int getHp();
    int getDamage();
    int getMoney();
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

void Ultraman::win(Monster& m) {
    if (m.getHp() <= 0) {
        money += m.getMoney();
        exp += m.getExp();
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

// 初始化（利用构造函数完成初始化），参数是等级，等级与其他属性的关系：
// 生命是等级20倍，攻击是等级2倍，金钱是等级的10倍，经验值是等级的10倍。
Monster::Monster(int _rank) :
rank(_rank), hp(20 * rank), damage(2 * rank),
money(10 * rank), exp(10 * rank) {}

void Monster::display() {
    printf("rank=%d hp=%d damage=%d exp=%d money=%d\n",
           rank, hp, damage, exp, money);
}

void Monster::attacked(Ultraman& u) {
    // 当奥特曼攻击时，怪兽受到的伤害等于奥特曼攻击力，即生命损失=奥特曼攻击力值
    hp -= u.getDamage();
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
int main()
{
    int t;
    cin >> t;   //表示有t个测试实例
    // 每个实例就是奥特曼与怪兽的1对1战斗
    while (t--) {
        //1. 输入奥特曼和怪兽的等级，并调用初始化方法进行对象初始化
        int u_rank, m_rank;
        cin >> u_rank >> m_rank;
        //2. 输出奥特曼和怪兽状态，调用display方法，每行输出一个
        Ultraman u(u_rank);
        u.display();
        Monster m(m_rank);
        m.display();
        //3. 设置战斗标志flag为true，启动战斗循环，具体如下：
        bool flag = true;
        while (flag) //当战斗未结束就继续
        {
            //奥特曼攻击1次，或者是怪兽被攻击1次
            m.attacked(u);
            /*怪兽没死*/
            //用怪兽生命来判断，用get方法啦
            if (m.getHp()>0) {
                //怪兽反击1次，或者是奥特曼被攻击1次
                u.attacked(m);
                /*奥特曼不必逃跑
