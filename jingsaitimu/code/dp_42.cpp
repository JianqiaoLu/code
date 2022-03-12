#include "headl.h" 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> a(n, 0), b(n, 0);
        for (int i = 1; i < n; i++)
        {
            a[i] = max(a[i - 1], height[i - 1]);
            b[n - 1 - i] = max(b[n - 1 - i], height[n - 1 - i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += max((min(a[i], b[i]) - height[i]), 0);
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 4,2,0,3,2,5 };
    a->trap(b);

}
