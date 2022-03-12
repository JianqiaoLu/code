#include "headl.h" 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount + 1, 0);
        sort(coins.begin(), coins.end());
        for (int i = 1; i < amount + 1; i++)
        {
            int a = 2e4;
            bool flag = true;
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] < 0) break;
                else
                {
                    if (ans[i - coins[j]] == -1) continue;
                    else
                    {
                        a = min(a, ans[i - coins[j]] + 1);
                        flag = false;
                    }
                }
            }
            if (flag) ans[i] = -1;
            else ans[i] = a;
        }
        return ans[amount];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<int> b = { 1,2,5 };
    Solution* a = new Solution();
    a->coinChange(b, 11);

}
