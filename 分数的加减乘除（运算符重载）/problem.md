# 分数的加减乘除（运算符重载）  
  
## 题目描述  
Fraction类的基本形式如下：  
```  
class Fraction {  
int numerator, denominator;  
int common_divisor();  
void contracted();  
public:  
Fraction(int=0; int=1);  
Fraction(Fraction&);  
Fraction operator+(Fraction);  
Fraction operator-(Fraction);  
Fraction operator*(Fraction);  
Fraction operator/(Fraction);  
void Set(int=0,int=1);  
void disp() {cout << "fraction=" << numerator << "/" << denominator << endl;}  
};  
```  
要求如下：  
1.实现Fraction类；common_divisor()和contracted()函数体可为空，不实现具体功能。  
2.编写main函数，初始化两个Fraction对象的，计算它们之间的加减乘除。  
## 输入  
第1行：依次输入第1个和第2个Fraction对象的分子和分母值。  
  
## 输出  
每行依次分别输出加减乘除计算后的Fraction对象（直接输出分数值，不需要约简）。  
  
## 样例输入  
1 3 2 5  
## 样例输出  
fraction=11/15  
fraction=-1/15  
fraction=2/15  
fraction=5/6  
## 提示  
  
