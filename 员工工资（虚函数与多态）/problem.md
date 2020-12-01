 # 员工工资（虚函数与多态）  
  
 ## 题目描述  
 某公司员工的属性有：姓名、职位、级别、工作年限，级别和年限都是非负整数，否则显示错误。包含方法有：构造函数，计算工资的方法（salary()）。  
  
 员工职位分为三种：Employee、Teamleader、Manager，其他职位类型显示错误。  
  
 三种职位员工的区别在于计算工资的方法不同：  
  
 1. Employee的每月工资 = 1000 + 500*级别 + 50*工作年限  
  
 2. Teamleader的每月工资 = 3000 + 800*级别 + 100*工作年限  
  
 3. Manager的每月工资 = 5000 + 1000 * (级别+工作年限)  
  
 计算工资的方法返回每个员工的工资数。  
  
 要求：以普通员工为基类，组长和经理继承基类，程序中只能使用基类指针指向对象与调用对象的方法。  
  
 ## 输入  
 测试案例的个数 t  
  
 每行输入一个员工的信息：包括姓名、职位、级别、工作年限  
  
 ## 输出  
 输出相应员工的信息  
  
 如有错误信息，则输出错误信息，若职位信息与级别和年限信息同时出错，仅输出职位错误信息  
  
 ## 样例输入  
 5  
 zhangsan Employee 4 5  
 lisi Teamleader 4 5  
 Wangwu Manager 4 5  
 chenliu Precident 4 5  
 xiaoxiao Manager -1 5  
 ## 样例输出  
 zhangsan:Employee,Salary:3250  
 lisi:Teamleader,Salary:6700  
 Wangwu:Manager,Salary:14000  
 error position.  
 error grade or year.  
   
  
