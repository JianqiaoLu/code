#include "headl.h" 
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> pre(row + 1, vector<int>(col + 1, 0));
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int r1 = max(i - k, 0), c1 = max(j - k, 0), r2 = min(i + k, row - 1), c2 = min(j + k, col - 1);
                ans[i][j] = pre[r2 + 1][c2 + 1] + pre[r1][c1] - pre[r1][c2 + 1] - pre[r2 + 1][c1];
            }
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
