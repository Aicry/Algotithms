#include<iostream>
#include<vector>
#include<math.h>
#include<map>
using namespace std;

map<int, vector<int>> m;

    

int main(){
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n;++i){
        int t;
        cin >> t;
        res.push_back(t);
        m[t].push_back(i);
     }

     for (int i = 0; i < n;++i){
         int p = m[res[i]].size();
         if(p==1)
             cout << -1<<" ";
         else {
             int temp = 9999999;
             for (int j = 0; j < p;++j){
                 if(m[res[i]][j]!=i){
                      int q = m[res[i]][j] - i;
                      if(q<0)
                          q = -q;
                     temp = min(temp, q);
                 }
             }
             cout << temp << " ";
         }
     }
}