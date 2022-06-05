/*
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
*/

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int res = 0;
vector<int> r;
vector<vector<int>> rs;
void fun(int n,int k,int p){
    if(n<0)
        return;
     if(k==0)
        {
            if(n==0)rs.push_back(r);
            return ;
        }

        for (int i = pow(n,(double) 1 / p); i >= 1; --i)
        {
            if(!r.empty()&&i>r.back())
                continue;
            if((n-pow(i,p))>=0)
              {
                  r.push_back(i);
                  fun(n - pow(i, p), k - 1, p);
                  r.pop_back();
              }
        }
}

int main(){
    int n, k, p;
    cin >> n >> k >> p;
    fun(n, k, p);

   if(rs.empty())
     {  
         cout << "Impossible";
         return 0;
     }
   int maxsum = 0;
   vector<int> result;
   for (int i = 0; i < rs.size();++i){
       int sum = 0;
       for (int j = 0; j < rs[i].size();++j){
           sum += rs[i][j];
       }
       if(sum==maxsum)
           {
               for (int z = 0; z < k;++z){
                   if(rs[i][z]>result[z]){
                       result = rs[i];
                       break;
                   }
                   if(rs[i][z]<result[z]){
                       break;
                   }
               }
           }
       if(sum>maxsum)
           result = rs[i];
   }
     
     /*169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2*/
   cout << n << " = ";
   for (int i = 0; i < k;++i){
       if(i==k-1)
           cout << result[i] << "^" << p;
    else
        cout << result[i] << "^" << p << " + ";
   }
}