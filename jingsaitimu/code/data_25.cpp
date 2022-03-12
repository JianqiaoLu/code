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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* a = new ListNode(-1, head);
        ListNode* ans;
        ListNode* nk = head;
        for (int i = 1; i < k; i++)
        {
            nk = (nk == nullptr) ? nullptr : nk->next;
        }
        while (nk != nullptr)
        {
            ListNode* b = a->next;
            ListNode* c = a->next->next;
            int d = 1;
            ListNode* nh = b;
            nk = (nk == nullptr) ? nullptr : nk->next;
            nh->next = nk;
            while (d < k)
            {
                ListNode* nxt = c->next;
                a->next = c;
                c->next = b;
                b = c;
                c = nxt;
                nk = (nk == nullptr) ? nullptr : nk->next;
                d++;
            }
            ans = (ans == nullptr) ? a->next : ans;
            a = nh;
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    Solution* a = new Solution();
    ListNode* head = new  ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* ans = a->reverseKGroup(head, 1);
    while (ans != nullptr)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}
