#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

vector<vector<int>> map;
int n;
double p, r;
int depth = 0, sum = 0;
void dfs(int dep,int k){
     if(map[k].size()==0){
          if(dep>depth){
              depth = dep;
              sum = 1;
          }
          else  if(dep==depth)
              sum++;
          return;
     }
     for (int i = 0; i < map[k].size();++i){
         dfs(dep + 1, map[k][i]);
     }
}

int main(){
    cin >> n >> p >> r;
    map.resize(n);
    int t;
    int head;
    for (int i = 0; i < n;++i){
        cin >> t;
        if(t==-1)
            head = i;
        else
        map[t].push_back(i);
    }
    dfs(0, head);
    cout <<fixed<<setprecision(2)<<p*pow((1+r*0.01),depth) << " " << sum;
}