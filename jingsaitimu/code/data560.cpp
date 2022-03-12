#include "headl.h" 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sums = 0;
        int num  = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sums+= nums[i];
            int l = 0, indi = sums;
            while (l < i)
            {
                if (indi == k)
                {
                    num ++;
                }
                indi -= nums[l];
                l ++ ;
            }
        }
        return num;
    }
// public:
    // int subarraySum(vector<int>& nums, int k) {
        // int l = 0, r = 1, num = 0;
        // int sum = nums[0];
        // if (sum == k) num++;
        // while (r < nums.size())
        // {
            // sum += nums[r];
            // if (sum == k)
            // {
                // num ++ ;
            // }
            // 
            // while ((sum - nums[l]) >= k)
            // {
                // sum -= nums[l];
                // l++;
                // if (sum == k)
                // {
                    // num++;
                // }
            // }
            // r++;
        // }
        // return num;
    // }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
