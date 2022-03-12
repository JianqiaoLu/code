#include "headl.h" 
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans(target + 1, 0);
        ans[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] <= i)
                {
                    ans[i] += ans[i - nums[j]];
                }
                else
                {
                    break;
                }
            }
        }
        return ans[target];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
