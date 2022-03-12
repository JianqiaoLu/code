#include "headl.h" 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), m = nums[0];
        vector<int> a(n + 1, 1), b(n + 1, 1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                a[i + 1] = nums[i] * a[i];
                b[i + 1] = nums[i] * b[i];
                m = max(a[i + 1], m);
            }
            else if (nums[i] < 0)
            {
                b[i + 1] = nums[i] * a[i];
                a[i + 1] = (nums[i] * b[i] > 0) ? nums[i] * b[i] : 1;
                m = max(nums[i] * b[i], m);
            }
            else
            {
                m = max(m, 0);
            }

        }
        return m;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
