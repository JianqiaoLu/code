#include "headl.h" 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ,ans = nums[0];
        vector<int> a(n + 1, 0);
        vector<int> b(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            a[i + 1] = max(a[i], nums[i] + a[i - 1]);
            b[i + 1] = max(b[i], nums[i - 1] + b[i - 1]);
            ans = max(ans,max(a[i+1], b[i+1]));
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
