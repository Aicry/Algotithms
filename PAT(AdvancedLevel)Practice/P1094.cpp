#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int child_num;
    int level;
    node *child[101];
};

node member[101];
int main(){
    int m, n;
    cin >> m >> n;
    
    int id, child_num, child_id;
    for (int i = 0; i < n;++i){
        cin >> id >> child_num;
        member[id].child_num = child_num;
        for (int j = 0; j < child_num;++j){
            cin >> child_id;
            member[id].child[j] = &member[child_id];
        }
    }
    member[1].level = 0;
    queue<node*> q;
    int res[100] = {0};
    int maxlevel=0;
    q.push(&member[1]);
     while(!q.empty()){
        node* first = q.front();
        int n = first->child_num;
        maxlevel = max(first->level, maxlevel);
        res[first->level]++;
        q.pop();
        for (int i = 0; i < n;++i){
            q.push(first->child[i]);
            first->child[i]->level= first->level + 1;
        }      
    }

    int a = 0, b = 0;
    for (int i = 0; i <= maxlevel;++i){
         if(res[i]>a)
             a = res[i], b = i;
    }
    cout << a << " " << b+1;
}