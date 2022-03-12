#include "headl.h" 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            ans[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == 0) ans[i][j] = min(ans[i - 1][j], ans[i - 1][j + 1]);
                else if (j == m - 1)  ans[i][j] = min(ans[i - 1][j], ans[i - 1][j - 1]);
                else
                    ans[i][j] = min(ans[i - 1][j], min(ans[i - 1][j - 1], ans[i - 1][j + 1])) + matrix[i][j];
            }
        }
        int a = ans[n - 1][0];
        for (int i = 1; i < m; i++)
        {
            a = min(a, ans[n - 1][i]);
        }
        return a;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
