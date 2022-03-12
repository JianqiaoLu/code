#include "headl.h" 
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> ans(n + 1, vector<bool>(m + 1, false));
        ans[0][0] = true;
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*' or p[j - 1] == '?')
            {
                ans[0][j] = ans[0][j - 1];
            }

        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[j - 1] == s[i - 1] or p[j - 1] == '?') ans[i][j] = ans[i - 1][j - 1];
                else if (p[j - 1] == '*') ans[i][j] = ans[i - 1][j] or ans[i][j - 1];
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
