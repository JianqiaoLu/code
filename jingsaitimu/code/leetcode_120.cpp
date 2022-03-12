#include "headl.h" 
class Solution {
public:
    vector<vector<int>> ans;
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> ans = triangle;
        for (int i = ans.size() -2 ; i >= 0; i--)
        {
            for (int j = 0; j < ans[i].size(); j ++)
            {
                ans[i][j] = min(ans[i+1][j], ans[i+1][j+1]) + triangle[i][j];
            }
        }
    return ans[0][0];
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
