#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<vector<int>> map;
set<int> S;
 int n;
int maxdepth=0;
vector<bool> vis(n+1,false);
void dfs(int node,int depth){
    if (depth > maxdepth){
        maxdepth = depth; 
        S.clear();
        S.insert(node);
    }
    else if (depth == maxdepth){
        S.insert(node);
    }
   
    vis[node] = true;
    for (int i = 0; i < map[node].size(); i++)
    {
        int m = map[node][i];
        if (vis[m] == false )
        {
            depth++;
            dfs(m, depth);
            depth--;
        }
   }
}
int main(){
   
    cin >> n;
     map.resize(n+1);
    //稀疏矩阵，需用邻接表存储边，否则内存超限
    for (int i=1; i<n; i++){
        int j, k;
        cin >> j >> k;
        map[j].push_back(k);
        map[k].push_back(j);  
    }

     int mount = 0;
     for (int i = 1; i <= n;++i){
             if (vis[i] == false)
             {
                 mount++;
                 dfs(i, 1);
             }
        
     }
      if(mount>1)
      {
          cout << "Error: " << mount << " components";
          return 0;
      }

         
             set<int> oldSet = S;
             int k = *S.begin();
             S.clear();
             fill(vis.begin(), vis.end(), false);
             maxdepth = 0;
             dfs(k, 1);
             for (auto it = oldSet.begin(); it != oldSet.end(); ++it)
             {
                 S.insert(*it);
        }
             for (auto it = S.begin(); it != S.end(); ++it)
             {
                 cout << *it << endl;
        }

        return 0;
}


/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int map[1005][1005];
int n;
int maxdepth=0;
bool vis[1005]={false};
void dfs(int node,int depth){
    maxdepth = max(depth, maxdepth);
    vis[node] = true;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false && map[node][i] == 1)
        {
            depth++;
            dfs(i, depth);
            depth--;
        }
   }
}
int main(){
    cin >> n;
     if(n<=0){
        cout << "Error: " << 0 << " components";
          return 0;
    }
    
    int a, b;
    for (int i = 1; i < n;++i){
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    int res[1005];
    int mount = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false)
        {
            mount++;
            dfs(i, 1);
        }
        
     }
      if(mount>1)
      {
          cout << "Error: " << mount << " components";
          return 0;
      }

         for (int j = 1; j <= n; ++j)
         {

             fill(vis, vis + 1005, false);
             dfs(j, 1);
             res[j] = maxdepth;
             maxdepth = 0;
         }
       int d = 0;
       for (int i = 1; i <= n;++i){
           d = max(res[i], d);
       }

       for (int i = 1; i <= n;++i){
             if(d==res[i])
                 cout << i << endl;
       }
      
}*/