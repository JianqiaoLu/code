#include "headl.h" 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0)
            {
                break;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if ((nums[i] + nums[l] + nums[r]) == 0)
                {
                    ans.push_back({ nums[i], nums[l], nums[r] });
                    while (l < r and nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                    while (l < r and nums[r] == nums[r - 1])
                    {
                        r--;
                    }
                }
                if ((nums[i] + nums[l] + nums[r]) < 0) l++;
                else r--;
            }
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { -1,0,1,2,-1,-4 };
    a->threeSum(b);

}
