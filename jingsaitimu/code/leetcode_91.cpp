#include "headl.h" 
class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();
        if (n == 0 or (n == 1 and s[0] == '0')) return 0;
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '0')
            {
                if (i == 1) return 0;
                else if (i > 1 and (s[i - 2] == '1' or s[i - 2] == '2'))
                {
                    ans[i] = ans[i - 2];
                }
                else return 0;
            }
            else
            {
                if (i == 1) ans[i] = 1;
                else
                {
                    if (s[i - 2] != '0')
                    {
                        int v = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                        if (v <= 26) ans[i] = ans[i - 1] + ans[i - 2];
                        else ans[i] = ans[i - 1];
                    }
                    else
                    {
                        ans[i] = ans[i - 1];
                    }
                }
            }
        }
        return ans[n];

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->numDecodings("1201234");

}
