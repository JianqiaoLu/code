#include "headl.h" 
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* l = head;
        ListNode* r = head;
        while (r!=nullptr and  r->next != nullptr)
        {
            l = l->next;
            r = r->next->next;
        }
        r = l->next;
        l->next = nullptr;
        ListNode* a = new ListNode(-1, r);
        ListNode* b = a->next->next;
        a->next->next = nullptr;
        while (b != nullptr)
        {
            ListNode* c = a->next;
            ListNode* nxt = b->next;
            a->next = b;
            b->next = c;
            b = nxt;
        }
        l = head;
        r = a->next;
        while (r != nullptr)
        {
            ListNode* tmp = l->next;
            l->next = r;
            l = tmp;
            ListNode* tmp2 = r->next;
            r->next = tmp;
            r = tmp2;
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
