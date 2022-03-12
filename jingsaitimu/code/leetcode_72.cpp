#include "headl.h" 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> ans(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= m; i++)
        {
            ans[0][i] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            ans[i][0] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int a = 1000;
                if (word1[i - 1] == word2[j - 1]) ans[i][j] = ans[i - 1][j - 1];
                else
                {
                    a = min(min(ans[i][j - 1], ans[i - 1][j]), ans[i - 1][j - 1]) + 1;
                    ans[i][j] = a;
                }
            }
        }
        return ans[n][m];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
