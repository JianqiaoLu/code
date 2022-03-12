#include "headl.h" 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size(), h = 0, b = matrix.size();
        vector<int> ans;
        int i, j;
        i = h;
        while (l < r and h < b)
        {

            for (j = l; j < r; j++)
            {
                ans.push_back(matrix[i][j]);
            }
            j--;
            h++;
            for (i = h; i < b; i++)
            {
                ans.push_back(matrix[i][j]);
            }
            i--;
            r--;
            if (l < r and h < b)
            {
                for (j = r - 1; j >= l; j--)
                {
                    ans.push_back(matrix[i][j]);
                }
                j++;
                b--;
                for (i = b - 1; i >= h; i--)
                {
                    ans.push_back(matrix[i][j]);
                }
                i++;
                l++;
            }
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<vector<int>> b = { {1,2,3},{4,5,6},{7,8,9} };
    Solution* a = new Solution();
    a->spiralOrder(b);

}

