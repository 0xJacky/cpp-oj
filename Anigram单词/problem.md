 # Anigram单词  
  
 一个单词a如果通过交换单词中字母的顺序可以得到另外的单词b，那么定义b是a的Anigram，例如单词army和mary互为Anigram。现在给定一个字典，输入Q个单词，从给出的字典中找出这些单词的Anigram。  
 Input  
 第1行：1个数N，表示字典中单词的数量。(1 <= N <= 10000)  
 第2 - N + 1行，字典中的单词，单词长度 <= 10。  
 第N + 2行：查询的数量Q。(1 <= Q <= 10000)  
 第N + 3 - N + Q - 2行：用作查询的单词，单词长度 <= 10。  
 Output  
 共Q行，输出Anigram的数量，相同的2个单词不算Anigram，如果没有输出0。  
 Input示例  
 5  
 add  
 dad  
 bad  
 cad  
 did  
 3  
 add  
 cac  
 dda  
 Output示例  
 1  
 0  
 2  
   
  
