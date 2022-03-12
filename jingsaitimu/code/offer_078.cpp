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
    vector<ListNode*> ans;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ans = lists;
        if(ans.empty()) return nullptr;
        return get(0, ans.size() - 1);
    }
    ListNode* get(int l, int r)
    {
        if (l == r) return ans[l];
        else
        {
            ListNode* ls = get(l, l + (r - l) / 2);
            ListNode* rs = get(l + (r - l) / 2 + 1, r);
            ListNode* gogo = new ListNode(-1);
            ListNode* real = gogo;
            while (ls or rs)
            {
                ListNode* nxt;
                nxt = ls ? (rs ? ((ls->val > rs->val) ? rs : ls) : ls) : rs;
                if (nxt == ls) ls = ls->next;
                else rs = rs->next;
                gogo->next = nxt;
                gogo = gogo->next;
            }
            return real->next;
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
