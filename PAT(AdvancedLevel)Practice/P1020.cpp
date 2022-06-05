#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> res;
struct node
{
    int _data;
    node* _left;
    node* _right;

    node(const int& x)
        :_data(x)
        , _left(NULL)
        , _right(NULL)
    {}
};
vector<int> por;
vector<int> inor;

node*  level(int l,int r){

    node *root=NULL;
    if(l>r){
        return root;    
    }
    
    for (int i = por.size() - 1; i >= 0;--i ){
        int mark = 0;
        for (int j = l; j <=r;++j){
            if(por[i]==inor[j]){
                root = new node(por[i]);
                root->_left= level(l, j-1);
                root->_right=level(j + 1, r);
                mark = 1;
            } 
            if(mark)
                break;
        }
          if(mark)
              break;
    }
    return root;
}
  void level_order(node* _root)
    {
        queue<node *>q;
        if (_root)
            q.push(_root);
        while (!q.empty())
        {
            node* front = q.front();
            res.push_back(front->_data);
            q.pop();
            if (front->_left)
                q.push(front->_left);
            if (front->_right)
                q.push(front->_right);
        }
    }
int main(){
    int n;
    cin >> n; 
    int t;
    for (int i = 0; i < n;++i){
        cin >> t;
        por.push_back(t);
    }
    for (int i = 0; i < n;++i){
        cin >> t;
        inor.push_back(t);
    }
    node *root;
    root=level(0, n-1);
    level_order(root);
    for (int i = 0; i < res.size()-1;++i){
        cout << res[i]<<" ";
    }
    cout << res[res.size() - 1];
}
