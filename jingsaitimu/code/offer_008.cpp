#include "headl.h" 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int r = i, sum = 0;
            while (sum < target and r < nums.size())
            {
                sum += nums[r];
                r++;
            }
            if (r == n and sum < target) break;
            else ans = (ans == 0) ? r-i :min(ans, r - i );
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = {1,1,1,1,1,1,1,1};
    a->minSubArrayLen(11,b);

}
