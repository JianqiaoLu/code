#include "headl.h" 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        vector<int> mi(n,0);
        mi[0] = prices[0];
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, prices[i] - mi[i-1]);
            mi[i] = min(mi[i-1], prices[i]);
        }
        return ans;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
