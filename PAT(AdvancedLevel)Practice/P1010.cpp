#include<iostream>
#include<math.h>
using namespace std;

long long turn_decimal(string a,long long r){
    long long b[10];
    long long n = a.length();
    for (long long i = n - 1; i >= 0;--i){
        long long j = n - 1 - i;
        if(a[i]>='0'&&a[i]<='9')
            b[j] = (long long)a[i] - 48;
         if(a[i]>='a'&&a[i]<='z')
            b[j] = (long long)a[i] - 87;
    }
    long long sum = 0;
    for (long long i = 0; i < n;++i){
        sum += b[i] * pow(r, i);
    }
    return sum;
}

long long findrad(string s,long long num){
    if(num<16){       ///考虑一个数的情况
        if(turn_decimal(s, 10) == num)return num+1;
    }
      
    long long n = s.length();
    char c = '0';
    for (long long i = 0; i < n;++i){
        c = max(c, s[i]);
    }
    long long mi;
    if(c>='0'&&c<='9')
        mi = (long long)(c - '0');
    else
        mi = (long long)(c - 'a');
    long long ma = max(mi, num);
	while(mi<=ma){
		long long mid=(mi+ma)/2;
		long long t=turn_decimal(s,mid);
		if(t<0 || t>num) ma=mid-1;   //溢出等效t>num
		else if(t<num) mi=mid+1;
		else if(t==num)
            return mid;
    }
	return -1;
}

long long main(){

    string N1, N2;
    long long tag;
    long long radix;
    cin >> N1 >> N2 >> tag >> radix;
    if(tag==1) radix=findrad(N2,turn_decimal(N1,radix));
	else radix=findrad(N1,turn_decimal(N2,radix));
	if(radix!=-1) cout<<radix<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
}