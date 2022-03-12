#include "headl.h" 
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size(), col = mat[0].size(), mrow = row / 2, mcol = col / 2, s = 0;
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (int mrow = 0; mrow < row; mrow++)
        {
            for (int mcol = 0; mcol < col; mcol++)
            {
                s = 0;
                for (int i = mrow - k; i <= mrow + k; i++)
                {
                    for (int j = mcol - k; j <= mcol + k; j++)
                    {
                        if (i < 0 or i >= row or j < 0 or j >= col)
                        {
                            continue;
                        }
                        s += mat[i][j];
                    }
                }
                ans[mrow][mcol] = s;
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
