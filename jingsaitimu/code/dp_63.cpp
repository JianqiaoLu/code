#include "headl.h" 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> ans(row, vector<int>(col));
        for (int i = 0; i < row; i++)
        {
            if (obstacleGrid[i][0]) break;
            else ans[i][0] = 1;
        }
        for (int i = 0; i < row; i++)
        {
            if (obstacleGrid[0][i]) break;
            else ans[0][i] = 1;
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (obstacleGrid[i][j]) continue;
                ans[i][j] = ans[i-1][j]  + ans[i][j-1];
            }
        }
        return ans[row-1][col-1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
