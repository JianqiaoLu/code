#include "headl.h" 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ans(n, vector<int>(3, 0));
        ans[0][2] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            int a = max(ans[i - 1][0], ans[i - 1][1]);
            ans[i][0] = (i >= 2) ? max(a, ans[i - 2][1]) : a;
            ans[i][1] = ans[i - 1][2] + prices[i];
            int b = max(ans[i - 1][2], ans[i - 1][0] - prices[i]);
            ans[i][2] = (i >= 2) ? max(ans[i - 2][1] - prices[i], b) : b;
        }
        return max(ans[n - 1][0], max(ans[n - 1][1], ans[n - 1][2]));
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 1,4,2 };
    a->maxProfit(b);

}
