#include "headl.h" 
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> a(n), b(m), ans;
        for (int i = 0; i < n; i++)
        {
            int val = matrix[i][0], loc = 0;
            for (int j = 1; j < m; j++)
            {
                if (val > matrix[i][j])
                {
                    val = matrix[i][j];
                    loc = j;
                }
            }
            bool f = true;
            for (int k = 0; k < n; k++)
            {
                if (matrix[k][loc] > val)
                {
                    f = not f;
                    break;
                }
            }
            if (f) ans.push_back(val);
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
