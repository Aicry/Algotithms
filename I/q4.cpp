#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode *l;
    TreeNode *r;
    TreeNode() : val(0), l(nullptr), r(nullptr) {}
    TreeNode(char x) : val(x), l(nullptr), r(nullptr) {}
    TreeNode(char x, TreeNode *l, TreeNode *r) : val(x), l(l), r(r) {}
};

TreeNode *create(string f, string b, int ps, int pe, int is, int ie)
{
    if (ps > pe)
    {
        return nullptr;
    }
    TreeNode *node = new TreeNode(f[ps]);
    int pos;
    for (int i = is; i <= ie; i++)
    {
        if (b[i] == node->val)
        {
            pos = i;
            break;
        }
    }
    
    node->l = create(f, b, ps + 1, ps + pos - is, is, pos - 1);
   
    node->r = create(f, b, pe - ie + pos + 1, pe, pos + 1, ie);
 
    return node;
}

int main()
{
    string f = "DBACEGF";
    string b = "ABCDEFG";
    create(f, b, 0, 6, 0, 6);
    return 0;
}