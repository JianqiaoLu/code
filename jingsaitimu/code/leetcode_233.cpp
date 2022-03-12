#include "headl.h" 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lp = 0;
        int rp = 0;
        int n = nums.size() - 1;
        while (nums[lp] != 0)
        {
            lp++;
        }
        rp = lp;
        while (rp <= n)
        {
            if (nums[rp] != 0)
            {
                nums[lp] = nums[rp];
                nums[rp] = 0;
                lp++;
            }
            rp++;
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = {1};
    a->moveZeroes(b);

}
