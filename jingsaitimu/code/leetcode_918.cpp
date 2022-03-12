#include "headl.h" 
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), a, m, i, i1, ans = nums[0];
        for (i = n - 1; i > 0; i--)
        {
            if (nums[i] < 0)
            {
                i1 = (i + 1) % n;
                m = nums[i1];
                a = 0;
                for (int j = 0; j < n - 1; j++)
                {
                    int k = (i1 + j) % n;
                    if (a > 0) a += nums[k];
                    else a = nums[k];
                    m = max(m, a);
                }
                ans = max(ans, m);
            }
        }
        a = 0;
        for (int i = 0; i < n; i++)
        {
            if (a > 0) a += nums[i];
            else a = nums[i];
            ans = max(ans, a);
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 5,-3,5 };
    a->maxSubarraySumCircular(b);
}
