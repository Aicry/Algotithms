#include<iostream>
#include<vector>
#include<queue>


using namespace std;

struct node
{
    int id;
    node *left;
    node *right;
    node *parent;
};

node nodes[10];
vector<int> level;
vector<int> pre;

void levelorder(node* root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *first = q.front();
        q.pop();
        level.push_back(first->id);
        if(first->right)
            q.push(first->right);
        if(first->left)
            q.push(first->left);
    }
    
}

void preorder(node* root){
    if(root==NULL)
        return;
    preorder(root->right);
    pre.push_back(root->id);
    preorder(root->left);
}
int main(){
    node k;
    k.left = NULL;
    k.right = NULL;
    k.parent = NULL;
    for (int i = 0; i < 10;++i){
        nodes[i] = k;
    }

        int n;
        cin >> n;
    for (int i = 0; i < n;++i){
        nodes[i].id = i;
        char a, b;
        cin >> a >> b;
        if(a!='-'){
            nodes[i].left = &nodes[a - '0'];
            nodes[a - '0'].parent = &nodes[i];
        }
        if(b!='-'){
            nodes[i].right = &nodes[b - '0'];
            nodes[b - '0'].parent = &nodes[i];
        }
    
    }
    node *root;
    for (int i = 0; i < n;++i){
        if (nodes[i].parent == NULL)
            root = &nodes[i];
    }
    levelorder(root);
    preorder(root);
    for (int i = 0; i < level.size();++i){
        if(i==level.size()-1)
            cout << level[i];
        else
            cout << level[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < pre.size(); ++i)
    {
        if(i==pre.size()-1)
            cout << pre[i];
        else
            cout << pre[i] << " ";
    }
}