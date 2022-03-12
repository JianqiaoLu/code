#include "headl.h" 
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n, 0);
        vector<int> b(n, 1);
        vector<int> c(n, 0);
        a[0] = 1;
        c[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    b[i] = max(b[j] + 1, b[i]);
                }
            }
            a[i] = max(a[i - 1], b[i]);
        }
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[j] < nums[i])
                    {
                        if (b[j] + 1 == b[i])  c[i] += c[j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (b[i] == a[n - 1]) ans += c[i];
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 1,2,4,3,5,4,7,2 };
    a->findNumberOfLIS(b);
}
