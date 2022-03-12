#include "headl.h" 
class Solution {
public:
    vector<int> ans{ 0,0 };
    int rob(vector<int>& nums) {
        for (int i = 2; i < nums.size() + 2; i++)
        {
            ans.push_back(max(nums[i - 2] + ans[i - 2], ans[i - 1]));
        }
        return ans[ans.size() - 1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
