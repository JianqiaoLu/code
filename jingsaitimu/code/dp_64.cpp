#include "headl.h" 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        ans[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            ans[0][i] = ans[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            ans[i][0] = ans[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                ans[i][j] = min(ans[i-1][j], ans[i][j-1]) + grid[i][j];
            }
        }
        return ans[n-1][m-1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
