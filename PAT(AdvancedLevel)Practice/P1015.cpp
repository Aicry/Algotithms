#include<math.h>
#include<vector>
#include <iostream>
using namespace std;

int to_radix(int n,int radix)
{
    int c, m = 0;
    int s[100];
    while (n!=0)//数制转换，结果存入数组s[m]
	{
		c=n%radix;
		n=n/radix;
		m++;s[m]=c;   //将余数按顺序存入数组s[m]中
	}
    int sum = 0;
    for (int i = 0; i < m;++i){
        sum += s[i + 1]*pow(radix, m-i-1);
    }
    return sum;
}
bool isprime(int n){
    if(n<2)
        return false;
    for (int i = 2; i < n / 2 + 1;++i){
            if(n%i==0)
                return false;       
    }
    return true;
}
int main(){
    int a,b;
    vector<string> res;
    while (true)
    {
        cin >> a;
        if(a>=0)
         {
             cin >> b;
             cout << to_radix(a, b)<<endl;
             if(isprime(a)&&isprime(to_radix(a,b)))
                 res.push_back("Yes");
             else
                 res.push_back("No");
         }
         else
             break;

    }
    for (int i = 0; i < res.size();++i){
        cout << res[i] << endl;
    }
}