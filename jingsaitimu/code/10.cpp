#include "headl.h" 
class Solution {
public:
    bool isMatch(string s, string p) {
        // return matchbyrecursion(s,p,'1');
        int n = s.size();
        int m = p.size();
        // vector<vector<int> >  ans[]
        bool ans[n + 1][m + 1];
        memset(ans, false, sizeof(ans));
        // for (int )
        ans[0][0] =  true;
        for (int j = 2; j <= m; j ++)
        {
            if (p[j - 1] == '*' and j % 2 ==0 )
            {
              ans[0][j]  =  ans[0][j-2];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    ans[i][j] = ans[i - 1][j - 1];
                }
                else
                {
                    if (p[j - 1] == '*')
                    {
                        if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                        {
                            ans[i][j] = (ans[i][j - 2] or ans[i - 1][j]);
                        }
                        else
                        {
                            ans[i][j] = ans[i][j - 2];
                        }

                    }

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
    bool ans1 = a->isMatch("aa", "a*");
    int aaa = 1;
}
