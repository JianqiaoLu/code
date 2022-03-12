#include "headl.h" 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int l = 0;
        while (l < nums.size())
        {
            int r = (nums.size() - 1 > (l + k)) ? l + k : nums.size() - 1;
            for (int i = l + 1; i <= r; i++)
            {
                if (abs(long(nums[i] - nums[l])) <= t) return true;
            }
            l++;
        }
        return false;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
