#include "headl.h" 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m - 1] != nums[m] and nums[m + 1] != nums[m]) return m;
            else if (nums[m - 1] == nums[m])
            {
                if ((m - 1 - l) % 2 == 0) l = m + 1;
                else r = m - 2;
            }
            else
            {
                if ((m - l) % 2 == 0) l = m + 2;
                else r = m - 1;
            }
        }
        return nums[r];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
