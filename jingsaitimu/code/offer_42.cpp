#include "headl.h" 
class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> anss{ {nums[0],nums[0]} };
        for (int i = 1; i < nums.size(); i++)
        {
            vector<int> ans{ 0,0 };
            ans[1] = max(anss[i - 1][1] + nums[i], nums[i]);
            ans[0] = max(ans[1], anss[i - 1][0]);
        }
        return anss[nums.size() - 1][0];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
