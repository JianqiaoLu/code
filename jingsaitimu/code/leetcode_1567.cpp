#include "headl.h" 
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), m = 0;
        vector<int> a(n + 1, 0), b(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                a[i + 1] = a[i] + 1;
                b[i + 1] = (b[i] == 0) ? 0 : b[i] + 1;
            }
            else if (nums[i] < 0)
            {
                b[i + 1] =  a[i] + 1;
                a[i + 1] = (b[i] == 0) ? 0 : b[i] + 1;
            }
            m = max(a[i + 1], m);
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
