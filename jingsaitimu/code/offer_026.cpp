#include "headl.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* l = head;
        ListNode* r = head;
        while (r!=nullptr and r->next != nullptr and r->next->next)
        {
            l = l->next;
            r = r->next->next;
        }
        if(l->next == nullptr) return ;
        ListNode* b = get(l->next);
        l->next = nullptr;
        ListNode* a = head;
        while (a!=nullptr and b!=nullptr)
        {
            ListNode* nxa = a->next;
            ListNode* nxb = b->next;
            a->next = b;
            b->next = nxa;
            a = nxa;
            b = nxb;
        }
    }
    ListNode* get(ListNode* head)
    {
        ListNode* a = new ListNode(-1, head);
        ListNode* cur  = head->next;
        ListNode* pre = head;
        pre->next = nullptr;
        while (cur !=nullptr)
        {
            ListNode* nxt  = cur->next;
            cur->next = a->next;
            a->next = cur;
            cur = nxt;
        }
        return a->next;
    }
};


int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
