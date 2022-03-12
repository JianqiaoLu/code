#include "headl.h" 
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = 0;
        vector<int> ans(n + 1, 0);
        ans[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            if (nums[i - 1] == nums[i - 2])
            {
                ans[i] = ans[i - 1] + nums[i - 1];
            }
            else
            {
                int l = i;
                while (l > 0)
                {
                    if (nums[l - 1] < (nums[i - 1] - 1)) break;
                    l--;
                }
                ans[i] = ans[l] + nums[i - 1];
            }
            m = max(m, ans[i]);
        }
        return m;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = {2,2,3,3,3,4};
    a->deleteAndEarn(b);

}
