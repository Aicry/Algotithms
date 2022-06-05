#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int n;
vector<int> numerator;
vector<int> denominator;

int max_divisor (int a,int b)   //  辗转相除法求最大公约数 
{ 

int  m, n, c;
   m=a;   n=b;
   while(b!=0)            // 余数不为0，继续相除，直到余数为0 
   {
       c = a % b;
       a = b;
       b = c;
   }
   return a;
   
}
int min_mul(int a,int b)   //  辗转相除法求最小公倍数 
{

    int m, n, c;
    m = a;
    n = b;
    while (b != 0) //余数不为0，继续相除，直到余数为0
    {
        c = a % b;
        a = b;
        b = c;
   }
   return m*n/a;
   
}
int main()
{
    cin >> n;

int a, b;
    char c;

    for (int i = 0; i < n;++i){
        cin >> a >> c >> b;
    
    int k = max_divisor(fabs(a), fabs(b));
        a = a / k;
        b = b / k;
        numerator.push_back(a);
        denominator.push_back(b);
    }

    int mul = 1;
    for (int i = 0; i < n;++i){
        mul = min_mul(mul, denominator[i]);
    }

    int sum = 0;
    for (int i = 0; i < n;++i){
        numerator[i] = (mul / denominator[i]) * numerator[i];
        sum += numerator[i];
    }
    if(sum==0)
        {
            cout << 0;
            return 0;
        }
            if (sum / mul)
            {

                if (sum % mul)
                    cout << sum / mul << " ";
                else
                    cout << sum / mul;
                 sum = sum % mul;
             }
   
     if(sum) {  
        int  r = max_divisor(sum, mul);
         cout << sum / r << "/" << mul / r;
     }
}