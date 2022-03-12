#include "headl.h" 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> ans(cost.size() + 1,0);
        int n = cost.size() ;
        for (int i = 2; i < cost.size() + 1; i++)
        {
            ans[i] = min(ans[i-1] + cost[i-1], ans[i-2] + cost[i-2]);
        }
        return ans[n];

    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
