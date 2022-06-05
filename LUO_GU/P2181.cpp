#include<iostream>
using namespace std;
int main(){
    unsigned long long n;
    cin>>n;
    unsigned long long sum=1;
    unsigned long long mid=0;
     unsigned long long res = 0;
    unsigned long long out = 0;
    for(unsigned long long i=3;i<n;++i){
         mid+=sum++;
         out+=mid;
         res += out;
    }
    cout<<res;
}