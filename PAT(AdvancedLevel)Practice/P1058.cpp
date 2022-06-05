#include<iostream>
using namespace std;
//测试点1

int main(){
    long long a, b, c;
    long long a1, b1, c1;
    long long a2, b2, c2;
    char t;
    cin >> a >> t >> b >> t >> c;
    cin >> a1 >> t >> b1 >> t >> c1;
    c2 = (c + c1) % 29;
    if((c+c1)/29){
        b2 = (b + b1 + 1) % 17;
    }
    else
        b2 = (b + b1) % 17;
    
    if((b+b1)/17){
        a2 = a + a1 + 1;
    }
    else
        a2 = a + a1;

    cout << a2 << t << b2 << t << c2;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int a1,b1,c1,a2,b2,c2;
	scanf("%d.%d.%d%d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	ll a=a1+a2,b=b1+b2,c=c1+c2;
	if(c>28){
		b+=c/29;
		c-=(c/29)*29;
	}
	if(b>16){
		a+=b/17;
		b-=(b/17)*17;
	}
	cout<<a<<"."<<b<<"."<<c;
	return 0;
}
*/