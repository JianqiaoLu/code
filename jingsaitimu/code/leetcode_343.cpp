#include "headl.h" 
class Solution {
public:
    int integerBreak(int n) {
        vector<int> a(n + 1);
        a[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int ans = -1;
            for (int j = 1; j < i; j++)
            {
                ans = max(ans, j * a[i - j]);
                ans = max(ans,j * (i-j));
            }
            a[i] =ans;
        }
        return a[n];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->integerBreak(10);

}
