#include "headl.h" 
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m, n;
        m = matrix[0].size();
        n = matrix.size();
        int ans[m + 1][n + 1][4];
        memset(ans, 0, sizeof(ans));
        // memset(ans[1][1], 1, sizeof(ans[1][1]));
        ans[1][1][0]  = 1;
        ans[1][1][1]  = 1;
        ans[1][1][2]  = 1;
        ans[1][1][3]  = 1;
        for (int k = 3; k <= m + n ; k++)
        {

            for (int i = 1; i < min(k,m + 1); i++)
            {
                int j = k - i;
                if (j > n)
                {
                    continue;
                }
                if (j - 2 >= 0)
                {
                    if (matrix[i - 1][j - 1] < matrix[i - 1][j - 2])
                    {
                        ans[i][j][0] = max(ans[i][j - 1][0], ans[i][j - 1][2]) + 1;
                    }
                    else if (matrix[i - 1][j - 1] > matrix[i - 1][j - 2])
                    {
                        ans[i][j][1] = max(ans[i][j - 1][1], ans[i][j - 1][3]) + 1;
                    }
                }
                if (i - 2 >= 0)
                {
                    if (matrix[i - 1][j - 1] < matrix[i - 2][j - 1])
                    {
                        ans[i][j][2] = max(ans[i-1][j][0], ans[i - 1][j ][2]) + 1;
                    }
                    else if (matrix[i - 1][j - 1] > matrix[i - 2][j - 1])
                    {
                        ans[i][j][3] = max(ans[i - 1][j][1], ans[i - 1][j ][3]) + 1;
                    }
                }
            }
        }
        int final = 0;
        pair<int,int> p;
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    final = (ans[i][j][k] > final)? ans[i][j][k]: final ;
                    if (ans[i][j][k] > final)
                    {
                        p.first = i;
                        p.second= j;
                    }
                    
                }

            }

        }
        return final;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution(); 
    vector<vector<int>> m = {{1,2},{3,4}};
    int ans1 = a->longestIncreasingPath(m);
    int aaa = 1;
}

