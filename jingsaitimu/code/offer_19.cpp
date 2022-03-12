#include "headl.h" 
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> ans(n + 1, vector<bool>(m + 1, false));
        ans[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '*')
            {
                ans[i][0] = ans[i - 2][0];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (p[i - 1] == '*')
            {
                ans[0][i] = ans[0][i - 2];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[j - 1] == '*')
                {
                    int r = i;
                    while (r > 0)
                    {
                        if (s[r - 1] == p[j - 2] or (p[j - 2] == '.')) r--;
                        else break;
                    }
                    bool flag = false;
                    int k;
                    if (r < 0) k = 0;
                    else k = r;
                    for (; k <= i; k++)
                    {
                        flag = flag or ans[k][j - 2];
                    }
                    ans[i][j] = flag;
                }
                else if (s[i - 1] == p[j - 1] or p[j - 1] == '.')
                {
                    ans[i][j] = ans[i - 1][j - 1];
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
    bool b = a->isMatch("aa", "a*");
    int c = 1;

}
