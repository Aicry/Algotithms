#include<iostream>
#include<map>
#include<iomanip>
#include<math.h>
#include<set>
#include<vector>
using namespace std;

struct node
{
    int pos;
    int val;
    int las;
    node *next;
};

int fis, num, k;
map<int, node> m;
map<int, node>::iterator iter;
vector<node *> v1, v2;
set<int> s;
void fun(node* head){
    while(head){
        if(s.find(fabs(head->val)) != s.end())
            v2.push_back(head);
        else
            {
                v1.push_back(head);
                s.insert(fabs(head->val));
            }
        head = head->next;
    }
}
int main(){
    cin >> fis >> num ;
    for (int i = 0; i < num;++i){
        int pos, val, las;
        cin >> pos >> val >> las;
        node t;
        t.pos = pos;
        t.val = val;
        t.las = las;
        m[pos] = t;
    }
    for (iter = m.begin(); iter != m.end();++iter){
        if(iter->second.las==-1)
            iter->second.next = NULL;
        else
            iter->second.next = &m[iter->second.las];
    }
    node *head = &m[fis]; 
    fun(head);
    int v1s = v1.size();
    int v2s = v2.size();
    for (int i = 0; i < v1s;++i){
          if(i==v1s-1)
              cout << setw(5) << setfill('0') << v1[i]->pos << " " << v1[i]->val << " "  << -1 << endl;
          else
              cout << setw(5) << setfill('0') << v1[i]->pos << " " << v1[i]->val << " " << setw(5) << setfill('0') << v1[i + 1]->pos << endl;

    }
      
    for (int i = 0; i < v2s;++i){
        if(i==v2s-1)
              cout << setw(5) << setfill('0') << v2[i]->pos << " " << v2[i]->val << " "  << -1 << endl;
        else
            cout << setw(5) << setfill('0') << v2[i]->pos << " " << v2[i]->val << " " << setw(5) << setfill('0') << v2[i + 1]->pos << endl;
    }
   
}






/*#include<iostream>
#include<map>
#include<iomanip>
#include<math.h>
using namespace std;

struct node
{
    int pos;
    int val;
    int las;
    node *next;
};

int fis, num, k;
map<int, node> m;
map<int, node>::iterator iter;

node* fun(node* head){
    node *fis;
    node dhead;
    node *del = &dhead;
    node *res = del;
    fis = head;
    while(fis->next)
   {
        node *pre = fis;
        while(pre->next)
       {  

        node *temp = pre->next;
        if(fabs(temp->val)==fabs(fis->val))
           {
                pre->next = temp->next;
                res->next = temp;
                res = temp;
           }
        else
            pre = pre->next;

       }
        fis = fis->next;
    }

    return del->next;
}
int main(){
    cin >> fis >> num ;
    for (int i = 0; i < num;++i){
        int pos, val, las;
        cin >> pos >> val >> las;
        node t;
        t.pos = pos;
        t.val = val;
        t.las = las;
        m[pos] = t;
    }
    for (iter = m.begin(); iter != m.end();++iter){
        if(iter->second.las==-1)
            iter->second.next = NULL;
        else
            iter->second.next = &m[iter->second.las];
    }
    node *head = &m[fis];
    node *del;
    del=fun(head);
    while(head){
        cout <<setw(5)<<setfill('0')<< head->pos << " " << head->val << " " << setw(5)<<setfill('0')<<head->next->pos << endl;
        head = head->next;
        if(head->next==NULL)
            {
                cout <<setw(5)<<setfill('0')<< head->pos << " " << head->val << " " << -1 << endl;
                head = head->next;
                }
    }
    while(del){
         cout <<setw(5)<<setfill('0')<< del->pos << " " << del->val << " " << setw(5)<<setfill('0')<<del->next->pos << endl;
         del = del->next;
          if(del->next==NULL)
            { 
                 cout <<setw(5)<<setfill('0')<< del->pos << " " << del->val << " " << -1 << endl;
                 del = del->next;
            }              

    }
}*/