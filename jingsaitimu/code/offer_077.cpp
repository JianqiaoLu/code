
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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode* cur = head;
        while (cur)
        {
            ans.push_back(cur->val);
            cur = cur->next;
        }
        sort(ans.begin(), ans.end());
        cur = head;
        for (int i = 0; i < ans.size(); i++)
        {
            cur->val = ans[i];
            cur = cur->next;
        }
        return head;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
