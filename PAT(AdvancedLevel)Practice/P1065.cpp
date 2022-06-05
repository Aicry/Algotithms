#include<iostream>
using namespace std;
int main()   ////?????????16
{
	int T;
	cin >> T;
	long long int A, B, C,sum;
	int i = 1;
	while (T--)
	{
		cin >> A >> B >> C;
		sum = A + B;
         cout << "Case #";
		if(A>0&&B>0&&sum<0)
            cout <<i<<": true";
        else if(A<0&&B<0&&sum>=0)
            cout <<i<<": false";
        else if (sum> C)
            cout <<i<<": true";
        else if(sum<=C)
            cout <<i<<": false";
        i++;
        cout << endl;
	}
}
/*#include <stdio.h>
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Case #%d: ",i+1);
        long long int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        long long int cnt=a+b;
        if(a>0&&b>0&&cnt<0)
        {
            printf("true\n");
        }
        else if(a<0&&b<0&&cnt>=0)
        {
             printf("false\n");
        }
        else if(cnt>c)
        {
            printf("true\n");
        }
        else if(cnt<=c)
        {
             printf("false\n");
        }
    }
}*/