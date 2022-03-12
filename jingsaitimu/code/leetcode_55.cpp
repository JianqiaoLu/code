#include "headl.h"
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> ans(n, false);
        ans[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
        {
            bool flag = false;
            for (int j = 1; j <= nums[i]; j++)
            {
                if (i + j > n)
                    break;
                flag = flag or ans[i + j];
            }
            ans[i] = flag;
        }
        return ans[0];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution *a = new Solution();
}
