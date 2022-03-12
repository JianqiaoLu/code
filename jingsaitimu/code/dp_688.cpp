#include "headl.h" 
class Solution {
public:
    vector<vector<int>> change = { {1, 2}, {2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> ans(n, vector<double>(n, 0));
        ans[row][column] = 1;
        for (int i = 0; i < k; i++)
        {
            vector<vector<double>> next(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (ans[i][j])
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            vector<int> loc = { i + change[k][0], j + change[k][1] };
                            if (loc[0] >= 0 and loc[0] < n and loc[1] >= 0 and loc[1] < n)
                            {
                                next[loc[0]][loc[1]] += ans[i][j] * 1.0/ 8;
                            }
                        }

                    }

                }
            }
            ans = next;
        }
        double ab = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ab += ans[i][j];
            }
        }
        return ab;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
