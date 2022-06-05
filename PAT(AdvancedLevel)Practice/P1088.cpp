#include<iostream>
#include<math.h>
using namespace std;
long long gcb (long long a,long long b)   //  辗转相除法求最大公约数 
{
    return b == 0 ? a : gcb(b, a % b);
}
void fun(long long n,long long d){
    if(n<0){
        cout << "(-";
        n = -n;
        if(n<d)
            cout << n << "/" << d;
        else
            {
                cout << n / d;
                if(n%d)
                    cout << " " << n % d << "/" << d;
            }
        cout << ")";
    }
   else if(n==0){
        cout << 0;
    }
   else  if(n>0){
        if(n<d)
            cout << n << "/" << d;
        else
            {
                cout << n / d;
                if(n%d)
                    cout << " " << n % d << "/" << d;
            }
    }
}
int main()
{
        long long d1, d2,n1,n2;
        char c;
        cin >> n1 >> c >> d1;
        long long k = gcb(fabs(n1), fabs(d1));
        n1 = n1 / k;
        d1 = d1 / k;
        cin >> n2 >> c >> d2;
        k = gcb(fabs(n2), fabs(d2));
        n2 = n2 / k;
        d2 = d2 / k;
    long long m = d1 * d2 / gcb(d1, d2);
    fun(n1, d1);
    cout << " + ";
    fun(n2, d2);
    cout << " = ";
    fun(n1 * (m / d1) + n2 * (m / d2), m);
    cout << endl;
    
    fun(n1, d1);
    cout << " - ";
    fun(n2, d2);
    cout << " = ";
    fun(n1 * (m / d1) - n2 * (m / d2), m);
    cout << endl;

    fun(n1, d1);
    cout << " * ";
    fun(n2, d2);
    cout << " = ";
    for(int i=1;i>0;i--){
        long long a = n1 * n2;
        long long b = d1 * d2;
        long long k = gcb(fabs(a), fabs(b));
        a = a / k;
        b = b / k;
        fun(a, b);
    }
    
    cout << endl;
    
    fun(n1, d1);
    cout << " / ";
    fun(n2, d2);
    cout << " = ";
    if(n2==0)
        cout << "Inf"; 
    else {
        long long a = n1 * d2;
        long long b = d1 * n2;
        long long k = gcb(fabs(a), fabs(b));
        a = a / k;
        b = b / k;
        if(b<0)
            fun(-a, -b);
        else
            fun(a, b);
        }
    cout << endl;

}