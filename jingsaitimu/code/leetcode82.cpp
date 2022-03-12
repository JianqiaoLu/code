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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* a = new ListNode(-200, head);
        int v = -200;
        ListNode* prev = a;
        ListNode* ans = a;
        a = a->next;
        while (a != nullptr)
        {
            if (a->next != nullptr)
            {
                if ((a->next->val == a->val) or (a->val == v))
                {
                    v = a->val;
                    a = a->next;
                }
                else
                {
                    prev->next = a;
                    prev = a;
                    a = a->next;
                }
            }
            else
            {
                if (a->val == v) prev->next = a->next;
                else prev->next = a;
            }
        }
        return ans->next;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
