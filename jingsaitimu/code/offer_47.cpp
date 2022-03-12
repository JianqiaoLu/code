#include "headl.h" 
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> ans = grid;
        ans.push_back(vector<int>(grid[0].size(), 0));
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i].push_back(0);
        }
        for (int k = grid.size() + grid[0].size() - 1; k >= 2; k--)
        {
            for (int i = grid.size(); i >= 1; i--)
            {
                int j = k - i;
                if (j < 1 or j > ans[0].size()) continue;
                ans[i - 1][j - 1] = max(ans[i - 1][j], ans[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return ans[0][0];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<vector<int>> b = {
  {1,3,1},
  {1,5,1},
  {4,2,1} };
    a->maxValue(b);

}
