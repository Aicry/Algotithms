#include<iostream>

using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


/*ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
*/

//递归
 ListNode* swapPairs(ListNode* head) {
         ListNode *a=head;
         int n = 0;
         while(a)
            {
                a = a->next;
                n++;
           }
           ListNode pre(0, head);
           ListNode *cur = &pre;
           ListNode *k = cur;
           for (int i = 0; i < n - 1; i += 2)
           {

               ListNode *node1 = k->next;
               ListNode *node2 = k->next->next;
               k->next = node2;
               node1->next = node2->next;
               node2->next = node1;
               k = node1;

               /* ListNode *temp = cur->next;
               ListNode *last = cur->next->next->next;
               cur->next = cur->next->next;
               cur->next->next = temp;
               cur = temp;
               cur->next = last;*/
            }
        return head;

    }

int main(){
    ListNode d(5);
    ListNode c(4, &d);
    ListNode b(3, &c);
    ListNode a(2, &b);
    ListNode head(1, &a);
    ListNode * k= swapPairs(&head);
    while (k!=NULL)
    {
        cout << k->val << "->";
        k = k->next;

   }
    

}