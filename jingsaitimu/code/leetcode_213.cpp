#include "headl.h"
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> a1(n + 1, 0), a2(n + 1, 0);
        a1[1] = nums[0];
        a2[2] = nums[1];
        for (int i = 2; i <= n; i++)
        {
            a1[i] = max(nums[i - 1] + a1[i - 2], a1[i - 1]);
            a2[i] = max(nums[i - 1] + a2[i - 2], a2[i - 1]);
        }
        return max(a2[n], a1[n - 1]);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution *a = new Solution();
    vector<int> b = {2,3,2};
    a->rob()
}
