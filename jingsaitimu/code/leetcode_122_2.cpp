#include "headl.h" 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), tr = 0, m = 0;
        vector<int> ans(n, 0);
        ans[0] = prices[0];
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > ans[i - 1])
            {
                if ((prices[i] - ans[i - 1]) > tr)
                {
                    tr = prices[i] - ans[i - 1];
                    ans[i] = ans[i - 1];
                }
                else
                {
                    ans[i] = prices[i];
                    m += tr;
                    tr = 0;
                }
            }
            else
            {
                ans[i] = prices[i];
                if(tr) m += tr;
                tr = 0;
            }
        }
        if(tr) m += tr;
        return m;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 2,1,2,0,1 };
    a->maxProfit(b);

}
