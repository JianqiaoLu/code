#include "headl.h" 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i >= 1 and nums[i] == nums[i - 1]) continue;
            else if (nums[i] > 0) break;
            int l = i + 1, r = n - 1;
            while (l < r and l < n and r >=0 )
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    ans.push_back({ nums[i],nums[l],nums[r] });
                    while ((l+1) < n and nums[l] == nums[l + 1]) l++;
                    while ((r-1) >= 0 and nums[r - 1] == nums[r]) r--;
                    l++;
                    r--;

                }
                else if (nums[i] + nums[l] + nums[r] > 0) r--;
                else if (nums[i] + nums[l] + nums[r] < 0) l++;
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
    vector<int> b  = {0,0,0,0};
    a->threeSum(b);

}
