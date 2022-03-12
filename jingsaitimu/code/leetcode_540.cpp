#include "headl.h" 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (m % 2)
            {
                if (nums[m] == nums[m - 1]) l = m + 1;
                else r = m;
            }
            else
            {
                if (nums[m] == nums[m + 1]) l = m + 1;
                else r = m;
            }
        }
        return nums[l];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
}
