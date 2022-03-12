#include "headl.h" 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m ;
            }
        }
        if (target == nums[l]) return l;
        int l1 = 0, r1 = l - 1, l2 = l + 1, r2 = nums.size()- 1;
        if (l == 0)
        {
            r1 = nums.size() - 1;
        }
        if (target >= nums[0])
        {
            while (l1 <= r1)
            {
                int m1 = l1 + (r1 - l1) / 2;
                if (nums[m1] > target)
                {
                    r1 = m1 - 1;
                }
                else if (nums[m1] < target)
                {
                    l1 = m1 + 1;
                }
                else
                {
                    return m1;
                }

            }
        }
        else
        {
            while (l2 <= r2)
            {
                int m1 = l2 + (r2 - l2) / 2;
                if (nums[m1] > target)
                {
                    r2 = m1 - 1;
                }
                else if (nums[m1] < target)
                {
                    l2 = m1 + 1;
                }
                else
                {
                    return m1;
                }

            }
        }
        return -1;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 8,9,2,3,4};
    a->search(b, 9);

}
