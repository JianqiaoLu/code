#include "headl.h" 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> ans;
        int l = 0, r = 1, n = nums.size(), val = nums[r] - nums[l];
        while (r + 1 < n)
        {
            if (nums[r + 1] == nums[r] + val) {
                r++;
            }
            else
            {
                if (r - l + 1 >= 3) ans.push_back(r - l + 1);
                l = r;
                r++;
                val = nums[r] - nums[l];
            }
        }
        if (r - l + 1 >= 3) ans.push_back(r - l + 1);
        int a;
        for (int i = 0; i < ans.size(); i++)
        {
            int l = 3;
            a += (1 + ans[i] - 3 + 1) * (ans[i] - 3 + 1) / 2;
        }
        return a;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> nums = { 1,2,3,4 };
    a->numberOfArithmeticSlices(nums);

}
