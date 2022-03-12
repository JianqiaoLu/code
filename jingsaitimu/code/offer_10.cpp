#include "headl.h" 
class Solution {
public:
    vector<int> ans{0,1};
    int fib(int n) {
        for (int i = 2; i <= n; i++)
        {
            ans.push_back((ans[i-1] + ans[i-2])%1000000007);
        }
        return ans[n];
}
    
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  a->fib(45);
  
}
