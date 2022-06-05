/*题目描述
有 2^n(n\le7)2 
n
 (n≤7) 个国家参加世界杯决赛圈且进入淘汰赛环节。我经知道各个国家的能力值，且都不相等。能力值高的国家和能力值低的国家踢比赛时高者获胜。1 号国家和 2 号国家踢一场比赛，胜者晋级。3 号国家和 4 号国家也踢一场，胜者晋级……晋级后的国家用相同的方法继续完成赛程，直到决出冠军。给出各个国家的能力值，请问亚军是哪个国家？

输入格式
无

输出格式
无

输入输出样例
输入 #1复制
3
4 2 3 1 10 5 9 7
输出 #1复制
1*/
#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     int id;
   };
   TreeNode a[150];
   TreeNode  Tree[600];


   TreeNode max_val(TreeNode a,TreeNode b){
     return a.val > b.val ? a : b;
   }
   TreeNode min_val(TreeNode a,TreeNode b){
     return a.val < b.val ? a : b;
   }
   
   void build_Tree(int node,int start,int end){  //node为根节点
          if(start==end)
           {
             Tree[node] = a[start];
             return;
           }
        int lnode = 2 * node;
        int rnode = 2 * node + 1;

        int mid = (end - start) / 2 + start;
        build_Tree(lnode, start, mid);
        build_Tree(rnode, mid + 1, end);
        Tree[node] = max_val(Tree[lnode], Tree[rnode]);
   }
int main(){
  int n;
  cin >> n;
  for (int i = 1; i <= (1 << n); i++)
  {
    cin >> a[i].val;
    a[i].id = i;
  }
  build_Tree(1, 1, (1 << n));
  cout << min_val(Tree[2], Tree[3]).id;
  return 0;
	
}