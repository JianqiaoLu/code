#include "headl.h" 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size();
        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (nums[m] < target) l = m + 1;
            else if (nums[m] > target)  h = m;
            else return m;
        }
        return l;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
