#include "headl.h" 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return { -1,-1 };
        int l = 0, r = nums.size() - 1;
        while (l < r - 1)
        {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m;
            }
        }
        int high, low;
        if (nums[r] == target)
        {
            high = r;
        }
        else if (nums[l] == target)
        {
            /* code */
            high = l;
        }
        
        else
        {
            return { -1, -1 };
        }
        l = 0;
        r = nums.size() - 1;
        while (l < r - 1)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        if (nums[l] == target)
        {
            low = l;
        }
        else if (nums[r] == target) low = r;
        else
        {
            return { -1, -1 };
        }

        return { low, high };

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<int> b {5,7, 7,8,8,10};
    Solution* a = new Solution();
    a->searchRange(b, 8);

}
