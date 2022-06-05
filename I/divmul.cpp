#include<iostream>
#include<vector>
using namespace std;

int max_divisor(int a,int b)   /*  辗转相除法求最大公约数 */ 
{ 
   int m, n, c;
   m=a;   n=b;
   while(b!=0)            /* 余数不为0，继续相除，直到余数为0 */ 
   {
       c = a % b;
       a = b;
       b = c;
   }
   return a;
   
}
int min_mul(int a,int b)   /*  辗转相除法求最大公约数 */ 
{ 
   int m, n, c;
   m=a;   n=b;
   while(b!=0)            /* 余数不为0，继续相除，直到余数为0 */ 
   {
       c = a % b;
       a = b;
       b = c;
   }
   return m*n/a;
   
}
int main(){

    cout << max_divisor(-4, 8) << endl;
    cout << min_mul(15, -27);

}