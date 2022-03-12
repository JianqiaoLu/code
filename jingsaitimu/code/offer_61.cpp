#include "headl.h" 
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int p = 0, n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!nums[i]) p++;
            else ans.push_back(nums[i]);
        }
        sort(ans.begin(), ans.end());
        int dis = 0;
        for (int i = 1; i < ans.size(); i++)
        {
            dis += ans[i] - ans[i - 1] - 1;
        }
        if (dis == p) return true;
        else return false;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = {8,8,11,12,10};
    a->isStraight(b);
}
