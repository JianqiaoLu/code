#include "headl.h" 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n, 0), b(n, 0);
        int sum1 = nums[0], sum2 = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            a[i] = sum1;
            b[n - 1 - i] = sum2;
            sum1 += nums[i];
            sum2 += nums[n - 1 - i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])  return i;
        }
        return -1;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
