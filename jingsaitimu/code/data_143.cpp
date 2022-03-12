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
        vector<ListNode*> a;
        while (head != nullptr)
        {
            a.push_back(head);
            head = head->next;
        }
        int l = 0, r = a.size() - 1;
        if (a.size() % 2 == 0)
        {
            while (l < r - 1)
            {
                a[r]->next = a[l]->next;
                a[l]->next = a[r];
                l++;
                r--;
            }
        }
        else
        {
            while (l < r)
            {
                a[r]->next = a[l]->next;
                a[l]->next = a[r];
                l++;
                r--;
            }
        }
        a[r]->next = nullptr;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
