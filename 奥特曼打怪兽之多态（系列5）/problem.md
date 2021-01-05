# 奥特曼打怪兽之多态（系列5）  
  
## 题目描述  
  
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
## 输入  
第1行输入奥特曼等级  
  
第2行输入怪兽个数  
  
对于每个怪兽，首先输入怪兽类别（‘M’或‘B’）  
  
如果是小怪兽，接着下一行输入怪兽等级  
  
## 输出  
输出战斗过程。具体参考Sample Output  
  
## 样例输入  
30  
3  
M  
5  
M  
5  
B  
## 样例输出  
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
## 提示  
  
