#include "headl.h" 
class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int go = 0;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == '1')
            {
                ans[i][0] = 1;
                go = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == '1')
            {
                ans[0][i] = 1;
                go = 1;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '0')
                {
                    continue;
                }
                else
                {
                    int l = min(ans[i - 1][j], ans[i][j - 1]);
                    while (l >= 0)
                    {
                        if (matrix[i - l][j - l] == '1')
                        {
                            ans[i][j] = l + 1;
                            break;
                        }
                        l--;
                    }

                    go = max(ans[i][j], go);

                }
            }
        }
        return  go * go;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
