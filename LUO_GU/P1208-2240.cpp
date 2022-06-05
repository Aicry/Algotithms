/*
struct Node{//金币结构体
	int w,v;//w表示重量，v表示价值
}a[110];

bool cmp(Node aa,Node bb){//定义排序方法
	return aa.v*bb.w>aa.w*bb.v;//按性价比从高到低排序，为防止精度问题直接交叉相乘
}
	sort(a+1,a+n+1,cmp);//排序
    */

#include<iostream>
using namespace std;

struct milk
{
    int v;
    int n;
}a[5001];

void sort(int l,int r)
{
    int i,mid,j;
    i=l;j=r;
    mid=a[(l+r)/2].v;
    while(i<=j)
    {
        while(a[i].v<mid)
        {
            i++;
        }
        while(a[j].v>mid)
        {
            j--;
        }
        if(i<=j)
        {
            milk t;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }
    if(l<j) sort(l,j);
    if(i<r) sort(i,r);
}

long long wmilk;
long long ans=0;
int n;
int main()
{
    cin>>wmilk>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].v>>a[i].n;
    }
    sort(0,n-1);

    int k=0;
    while(wmilk>a[k].n)
    {
        ans+=a[k].v*a[k].n;//装入所有
        wmilk=wmilk-a[k].n;
        k++;
    }
    ans+=wmilk*a[k].v;//装入最后的
    cout<<ans;
    return 0;
}
