 # 向量的加减（运算符<<重载）  
  
 ## 题目描述  
 设向量X=(x1,x2,…,xn)和Y=(y1,y2…,yn),它们之间的加、减分别定义为：  
   X+Y=(x1+y1,x2+y2,…,xn+yn)  
   X-Y=(x1-y1,x2-y2,…,xn-yn)  
 编程序定义向量类Vector ,重载运算符“+”、“-”,实现向量之间的加、减运算;并重载运算符”<<”作为向量的输出操作。  
 Vector类的基本形式如下：  
 ```  
 class Vector {  
     int vec[N];  
  
 public:  
     Vector(int v[N]);  
     Vector();  
     Vector operator+(Vector &v);  
     Vector operator-(Vector &v);  
     friend ostream &operator<<(ostream &cout, Vector &v);  
 };  
 ```  
 要求如下：  
 1.实现Vector类；  
 2.编写main函数，初始化两个Vector对象的，计算它们之间的加减，并输出结果。  
 ## 输入  
 第1行：输入10个int类型的值，初始化第一个Vector对象。  
 第2行: 输入10个int类型的值，初始化第一个Vector对象。  
 ## 输出  
 第1行：2个Vector对象相加后的输出结果。  
 第2行：2个Vector对象相减后的输出结果。  
 ## 样例输入  
 -4 1 0 10 5 -9 8 13 6 2  
 -11 8 10 17 -6 9 6 7 12 5  
 ## 样例输出  
 -15 9 10 27 -1 0 14 20 18 7  
 7 -7 -10 -7 11 -18 2 6 -6 -3  
 ## 提示  
   
  
