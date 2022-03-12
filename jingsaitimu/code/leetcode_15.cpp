#include "headl.h" 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0) break;
            else if (i > 0 and nums[i] == nums[i - 1]) continue;
            int k = n - 1;
            for (int j = i + 1; j < n; j++)
            {
                if (j >= k) break;
                else if (j > i + 1 and (nums[j] == nums[j - 1])) continue;
                else if (nums[i] + nums[j] + nums[k] == 0)
                {
                    ans.push_back({ nums[i],nums[j],nums[k] });
                    while (nums[k] == nums[k - 1]) k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0) break;
                else  k--;
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
