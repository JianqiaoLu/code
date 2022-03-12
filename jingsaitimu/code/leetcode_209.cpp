#include "headl.h" 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int prev = 0;
        int sum = nums[0];
        int n = nums.size();
        vector<int> ans(n);
        if (nums[0] >= target) 
        {
            ans[0] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            sum += nums[i];
            while (prev <= i)
            {
                if ((sum - nums[prev]) >= target)
                {
                    sum -= nums[prev];
                    prev++;
                }
                else
                {
                    break;
                }
            }
            if (ans[i-1]!= 0) ans[i] = min(i - prev + 1, ans[i - 1]);
            else
            {
                if (sum >= target) ans[i] = i - prev + 1;
                else ans[i] = 0;
            }
            // ans[i] = i - prev + 1;
        }
        return ans[n - 1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b  = {1,4,4};
    a->minSubArrayLen(4,b);

}
