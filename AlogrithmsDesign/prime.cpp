#include<stdio.h>
#define MAX 100
int s;
int a[MAX];
void prime()
{
    s=1;
    for(int i=0;i<=MAX;i++)
        a[i]=1;
    a[0]=a[1]=0;
    for(int i=2;i<=MAX;i++)
    {
        if(a[i])
            a[s++]=i;
        for(int j=i*2;j<=MAX;j+=i)
            a[j]=0;
    }
}
int main()
{
    prime();
    for(int i=1;i<s;i++)
        printf("%d\n",a[i]);
    return 0;
}