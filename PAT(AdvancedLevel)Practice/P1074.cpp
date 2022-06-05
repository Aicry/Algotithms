#include<iostream>
#include<map>
#include<iomanip>
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

node* reverse(node* head){
        int d = 0;
        node* fis = head;
        while (fis != NULL) {
            if (++d >= k) break;
            fis = fis->next;
        }
        if (d < k) return head;
        node *prev = NULL;
        node *curr = head;
        for (int i = 0; i < k; ++i) {
            node* fis = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fis;
        }
        head->next = reverse(curr);
        return prev;




}
int main(){
    cin >> fis >> num >> k;
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

    head = reverse(head);
    while(head){
       if(head->next) head->las = head->next->pos;
       else
           head->las = -1;
       cout << setw(5) << setfill('0') << head->pos << " " << head->val << " ";
       if(head->las!=-1)
           cout << setw(5) << setfill('0') << head->las << endl;
        else
            cout << -1 << endl;
       head = head->next;
    }
    
    
}