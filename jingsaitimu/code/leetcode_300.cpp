#include "headl.h" 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n, 0);
        vector<int> b(n, 1);
        a[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    b[i] = max(b[j] + 1,b[i]);
                }
            }
            a[i] = max(a[i-1], b[i]);
        }
        return a[n-1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = {0,1,0,3,2,3};
    a->lengthOfLIS(b);

}
