/**
 * @file P1030.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-12
 * 
 * @copyright Copyright (c) 2020
 * 4 5 0 3
 * 0 1 1 20
 * 1 3 2 30
 * 0 3 4 10
 * 0 2 2 20
 * 2 3 1 20
 */

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
struct node
{
    int distance;
    int cost;
};
int num,roads,c,des;
node map[501][501];
bool vis[501] = {false};
vector<vector<int>> road;
vector<int> path;

void DFS(int c,vector<int> & path){
     path.push_back(c);
     vis[c] = true;
    if (c == des)
    {
        road.push_back(path);
        path.pop_back();
        vis[c] = false;
        return;
    }

      for (int i = 0; i < num; ++i)
      {
          if(vis[i]==false&&map[c][i].distance!=0)
              DFS(i, path);
      }
      path.pop_back();
      vis[c] = false;
}
int main(){

    node k;
    k.cost = 0;
    k.distance = 0;
    fill(map[0], map[0] + 500 * 500, k);
    cin >> num >> roads >> c >> des;
    for (int i = 0; i < roads;++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        map[a][b].distance = c;
        map[a][b].cost = d;
        map[b][a].distance = c;
        map[b][a].cost = d;
    }
    DFS(c, path);
    vector<int> res;
    int mark = 99999999;
    int mincost;
    for (int i = 0; i < road.size();++i){
        int sum = 0,cost=0;
        for (int j = 1; j < road[i].size();++j){
            sum += map[road[i][j - 1]][road[i][j]].distance;
            cost += map[road[i][j - 1]][road[i][j]].cost;
        }
        if(sum<mark){
            mark = sum;
            mincost = cost;
            res = road[i];
        }
        if(sum==mark){
            if(cost<mincost)
               mincost=cost, res = road[i];
        }

    }
    for (int i = 0; i < res.size();++i){
        cout << res[i] << " ";
    }
    cout << mark << " " << mincost;
}


/*#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int distance;
    int cost;
};
int num,road,c,des;
node map[500][500];
bool vis[500] = {false};
vector<vector<int>> roads;
vector<int> path;
int mindis = INT_MAX;
int minmon = INT_MAX;
void DFS(int c,vector<int> & path,int& sum,int &money){

    vis[c] = true;
    if (c == des)
    {
         if (sum == mindis)
        {
            if(money<minmon)
           {
               minmon = money;
               roads.clear();
               roads.push_back(path);
           }
        }
        if (sum < mindis)
        {
            mindis = sum;
            roads.clear();
            roads.push_back(path);
        }
        return;
      }
      for (int i = 0; i < num;++i){
          if(vis[i]==false&&map[c][i].distance!=0){
              sum += map[c][i].distance;
              money += map[c][i].cost;
              path.push_back(i);
              DFS(i, path, sum,money);
              vis[i] = false;
              path.pop_back();
              sum -= map[c][i].distance;
              money -= map[c][i].cost;
          }
      }

}
int main(){

    node k;
    k.cost = 0;
    k.distance = 0;
    fill(map[0], map[0] + 500 * 500, k);

    cin >> num >> road >> c >> des;
    for (int i = 0; i < road;++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        map[a][b].distance = c;
        map[a][b].cost = d;
         map[b][a].distance = c;
         map[b][a].cost = d;
    }
    int sum = 0,money=0;
    path.push_back(c);
    DFS(c, path,sum,money);
    
       int cost=0;
        cout << roads[0][0] << " ";
       for (int i = 1; i < roads[0].size();++i){
           cout << roads[0][i] << " ";
           cost += map[roads[0][i - 1]][roads[0][i]].cost;
       }
       cout << mindis << " " << cost;

}


*/

   /*
10 10 0 4
0 1 1 2
0 2 1 1
1 3 1 2
2 3 1 1
3 5 1 2
3 9 1 1
5 8 1 2
9 8 1 1
5 7 1 1
7 4 1 1

10 10 0 8
1 0 1 2
0 2 1 1
1 3 1 2
3 2 1 1
5 3 1 2
3 9 1 1
5 8 1 2
9 8 1 1
5 7 1 1
7 4 1 1

10 10 0 7
0 1 1 2
0 2 1 1
1 3 1 2
2 3 1 1

   */