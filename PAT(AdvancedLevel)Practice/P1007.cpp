#include<iostream>
using namespace std;
int a[10000];
/*
    In case that the maximum subsequence
    is not unique, output the one with the smallest indices i and j (as shown by the sample case). 
*/
int MaxsubSlow(int a[],int n,int &begin,int &end){
    if(n==0)
        return -1;
    if(n==2)
        return max(a[0], a[1]);
    int m = a[0];
    int res = a[0];
    for (int i = 1; i<n; ++i)
    {
       m = max(m+ a[i], a[i]);

        if(m>res&&m!=a[i])
            end = i;
        if(m>res&&m==a[i]&&res!=0)
            begin = i, end = i;
        if(m>res&&m==a[i]&&res==0)
            end = i;
        res = max(res, m);
        
    }
    
    return res;
}
int main(){
    int n;
    int begin=0, end=0;
    cin >> n;
    for (int i = 0; i < n;++i){
        cin >> a[i];
    }
    int res = MaxsubSlow(a, n, begin, end);
    if(res<0){
        cout <<0<<" "<<a[0]<<" "<<a[n-1];
    }
     else cout << res<<" "<<a[begin]<<" "<<a[end];
     //cout <<" "<< begin << " " << end;
}


/**
 * @brief 
 * 10
-10 1 2 3 4 -5 -6 3 7 -21
 * 1 5 -5 -5 8 9 -11 5 6 3 1 -5 10 -2
 * 
 * 
 * 5
   9 -9 9 -9 -9

   5 
   1 -1 0 1 0
 */