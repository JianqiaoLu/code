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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* start = head;
        ListNode* end;
        while (start != nullptr)
        {
            end = start->next;
            if(not end) break;
            int sum = 0;
            while (end->val != 0)
            {
                sum += end->val;
                end = end->next;
            }
            if (sum)
            {
                ListNode* a = new ListNode(sum);
                start->next = a;
                a->next = end;
            }
            start = end;
        }
        ListNode* pre = head;
        start = head->next;
        while (start != nullptr)
        {
            if (start->val == 0)
            {
                pre->next = start->next;
                pre = pre->next;
                if (pre == nullptr) break;
                start = pre->next;
            }
            else
            {
                pre =  start;
                start = start->next;
            }
        }
        return head->next;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
