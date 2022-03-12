#include "headl.h" 
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        else if (n == 2) return (nums[0] == nums[1]) ? 1 : 2;
        vector<int> a(n, 1), b(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                int c = nums[j] - nums[i];
                if (c > 0)
                {
                    a[i] = max(a[i], b[j] + 1);
                }
                else if (c < 0)
                {
                    b[i] = max(b[i], a[j] + 1);
                }
            }

        }
        return max(a[n-1], b[n-1]);

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
