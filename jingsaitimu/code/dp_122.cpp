#include "headl.h" 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ans (n, vector<int>(2));
        ans[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            ans[i][0] = max(ans[i-1][0], ans[i-1][1] + prices[i]);
            ans[i][1] = max(ans[i-1][0] - prices[i], ans[i-1][1]);
        }
        return ans[n-1][0];
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
