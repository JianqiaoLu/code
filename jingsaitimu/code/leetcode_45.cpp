#include "headl.h"
class Solution
{
public:
    int canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        ans[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int it = 1e5;
            bool f = false;
            for (int j = 1; j <= nums[i]; j++)
            {
                if (i + j > n)
                    break;
                else if (ans[i + j] < 0)
                    continue;
                f = true;
                it = min(1 + ans[i + j], it);
            }
            if (f) ans[i] = it;
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
