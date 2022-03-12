#include "headl.h" 
class Solution {
public:
    int numSquares(int n) {
        vector<int> ans(n + 1, -1);
        ans[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                if (ans[i - j * j] != -1)
                {
                    ans[i] = (ans[i] == -1) ? ans[i - j * j] + 1 : min(ans[i], ans[i - j * j]);
                }
            }

        }
        return ans[n];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
