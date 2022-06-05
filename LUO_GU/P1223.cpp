#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct peo{
    int time;
    int num;
} a[1000];
bool cmp(peo a,peo b){
    return a.time < b.time;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <n; ++i)
    {
        cin >> a[i].time;
        a[i].num=i+1;
  } 
  sort(a,a+n,cmp);
  
/* 
   double t1=0,t2=0;
  for(int i=1;i<n;++i)
  {
      t1+=a[i-1].time;
      t2+=t1;
      cout<<a[i].num<<" ";       
          }
      */
  double t2;
  for(int j=n-1;j>=1;j--) //等待人数的计数器，由n-1开始
  {
    int  i=n-1-j;//这是个规律，当前最少时间的人序号和要等待的人数之和=n
    t2+=a[i].time*j; //累加                  
  }
  t2/=n;
  cout<<endl<<fixed<<setprecision(2)<<t2;
  return 0;
}