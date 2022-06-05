
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
        if(n==0)
            res[first->level]++;
        q.pop();
        for (int i = 0; i < n;++i){
            q.push(first->child[i]);
            first->child[i]->level= first->level + 1;
        }      
    }

    for (int i = 0; i < maxlevel;++i){
        cout << res[i] << " ";
    }
    cout << res[maxlevel];
}
/*
7 4
02 2 04 05
01 2 02 03
03 1 06
05 1 07

*/

/*8 4
01 3 02 04 05
04 2 03 07*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];
int book[100], maxdepth = -1;
void dfs(int index, int depth) {
    if(v[index].size() == 0) {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&node, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 0);
    printf("%d", book[0]);
    for(int i = 1; i <= maxdepth; i++)
        printf(" %d", book[i]);
    return 0;
}
*/