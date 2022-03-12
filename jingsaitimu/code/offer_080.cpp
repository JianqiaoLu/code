#include "headl.h" 
class Solution {
public:
    vector<int> vis;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        get(n,k,1);
        return ans;
    }
    void get(int n, int k, int s)
    {
        if(k == 0) ans.push_back(vis);
        for (int i = s; i <= n; i++)
        {
            vis.push_back(i);
            get(n,k-1,i+1);
            vis.pop_back();
        }
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
