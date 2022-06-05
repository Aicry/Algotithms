#include<iostream>
#include<time.h>
using namespace std;


/* Compute prefix sum of vector a */
void psum1(long a[], long p[], long int n)
{
     long int i;
    p[0] = a[0];
    for (i = 1; i < n; i++)
        p[i] = p[i - 1] + a[i];
}
void psum2(long a[], long p[], long int n)
{
     long int i;
    p[0] = a[0];
    for (i = 1; i < n - 1; i += 2)
    {
        long mid_val = p[i - 1] + a[i];
        p[i] = mid_val;
        p[i + 1] = mid_val + a[i + 1];
     }
/* For odd n, finish remaining element */

if(i <n)
    p[i] = p[i - 1] + a[i];
}
int main(){
    long int n; 
    cin >> n;
    long  a[100000];
    long  p[100000];
    long  q[100000];
    for (long int i = 0; i < n;++i){
        a[i] = i;
    }
    clock_t t;
    t = clock();
    psum1(a, p, n);
    cout << "sum:" << p[n - 1]<<endl;
    t = clock() - t;
    cout << "psum1_time:"<<t<<endl;

    
    t = clock();
    psum2(a, q, n);
    cout << "sum:" << q[n - 1]<<endl;
    t = clock() - t;
    cout <<"psum2_time:"<< t<<endl;
}