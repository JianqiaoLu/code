#include "headl.h" 
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int prev = 0;
        int pm = nums[0];
        int n = nums.size();
        if (nums[0] < k)
        {
            ans++;
        }
        for (int i = 1; i < n; i++)
        {
            int loc = prev;
            int m = pm * nums[i];
            while (loc <= i)
            {
                if (m < k)
                {
                    ans += (i - loc) + 1;
                    prev = loc;
                    pm = m;
                    break;
                }
                else
                {
                    m /= nums[loc];
                    loc++;
                }
            }
            if (loc > i)
            {
                prev = i + 1;
                pm = 1;
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
    vector<int> b = { 57,44,92,28,66,60,37,33,52,38,29,76,8,75,22 };
    a->numSubarrayProductLessThanK(b, 18);

}
