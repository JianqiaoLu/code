#include "headl.h" 
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> ans(n, vector<bool>(n, true));
        int a = n;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                ans[j][i] = (s[i] == s[j]) and ans[j + 1][i - 1];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (ans[j][i]) a++;
            }
        }
        return a;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
