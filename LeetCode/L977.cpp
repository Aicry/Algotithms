 #include<iostream>
#include<vector>
using namespace std;
  vector<int> sortedSquares(vector<int>& a) {
     int n = a.size();
     int k = 0;
     for (int i = 0; i < n;++i){
         if(a[i]<0)
             k = i;
             else
                 break;
     }
     int l = k + 1;
     vector<int> res;
     while (k >=0 && l<n){
         if(a[l]+a[k]>=0)
             res.push_back(a[k] * a[k]), k--;
         else
         {
             res.push_back(a[l] * a[l]);
             l++;
         }
         
     }
     while(l<n)
         res.push_back(a[l] * a[l]),l++;

     while(k>=0)
             res.push_back(a[k] * a[k]),k--;

    
         return res;


    }
    int main(){
        vector<int> a{-4, -1, 0, 3, 10};
        vector<int> res;
        res = sortedSquares(a);
        for(int i:res)
            cout << i << ends;
        }