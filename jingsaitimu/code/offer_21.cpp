#include "headl.h" 
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] % 2) == 1)
            {
                swap(nums[i], nums[l++]);
            }
        }
        return nums;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
