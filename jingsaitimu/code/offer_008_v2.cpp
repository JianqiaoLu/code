#include "headl.h" 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int  l = 0, r = 0, sum = nums[0], ans = nums.size();
        while (r < nums.size())
        {
            if (sum >= target)
            {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
            else
            {
                r++;
                sum += nums[r];
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
    vector<int> b = { 2,3,1,2,4,3 };
    auto d = a->minSubArrayLen(7, b);
    int c = 1;

}
