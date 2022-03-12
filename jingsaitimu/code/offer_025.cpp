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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = get(l1);
        ListNode* b = get(l2);
        ListNode* f = new ListNode(-1);
        ListNode* ans = f;
        int c = 0;
        while (a!=nullptr or b!=nullptr or c)
        {
            int av = (a) ? a->val:0;
            int bv = (b) ? b->val:0;
            int d = c + av + bv;
            if(d >= 10) c= 1;
            else c = 0;
            d %= 10;
            ans->next = new ListNode(d);
            a = (a)? a->next:nullptr;
            b = (b)? b->next:nullptr;
            ans = ans->next;
        }
        return get(f->next);
    }
    ListNode* get(ListNode* head)
    {
        ListNode* a = new ListNode(-1, head);
        if(not head) return nullptr;
        ListNode* cur = head->next;
        ListNode* pre = head;
        pre->next = nullptr;
        while (cur != nullptr)
        {
            ListNode* nxt = cur->next;
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
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
