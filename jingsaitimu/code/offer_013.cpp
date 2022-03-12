#include "headl.h" 
class NumMatrix {
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        int x = matrix[0].size(), y = matrix.size();
        ans = vector<vector<int>>(y + 1, vector<int>(x + 1, 0));
        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {
                ans[j][i] = matrix[j - 1][i - 1] + ans[j - 1][i] + ans[j][i - 1] - ans[j - 1][i - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
          return ans[row2 + 1][col2 + 1] - ans[row1][col2 + 1] - ans[row2 + 1][col1] + ans[row1][col1];
    }
};

int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<vector<int>> b = { {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5 },{4,1,0,1,7},{1,0,3,0,5 } };
    NumMatrix* a = new NumMatrix(b);


}
