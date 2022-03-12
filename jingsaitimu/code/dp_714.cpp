#include "headl.h" 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> a (n,vector<int> (2,0));
        a[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            a[i][0] = max(a[i-1][0], a[i-1][1] + prices[i] - fee);
            a[i][1] = max(a[i-1][1], a[i-1][0] - prices[i]);
        }
        return max(a[n-1][0], a[n-1][1]);
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
