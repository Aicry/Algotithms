#include<iostream>
#include<algorithm>
using namespace std;
int map[1005][1005];
bool vis[1005]={false};
int rnum, check_num,cnum;
void dfs(int node){
  vis[node]=true;
  for(int i=1;i<=cnum;i++){
     if(vis[i]==false&&map[node][i]==1){
     dfs(i);
  }
}
}
int main(){
   
    cin >> cnum >> rnum >> check_num;
    int i, j;
    for (int k = 0; k < rnum;++k){
        cin >> i >> j;
        map[i][j] = 1;
        map[j][i] = 1;
    }
    int cid;
    int res = 0;
    for (int k = 0; k < check_num;++k){
        fill(vis, vis + 1005, false);
        res = 0;
        cin >> cid;
        vis[cid] = true;
        for (int i = 1; i <= cnum; ++i)
        {
            if (i == cid)
                continue;
            if(vis[i]==false){
                 dfs(i);
                res++;
          }
        }
        cout << res-1 << endl;

   }

}