#include "headl.h" 

class Solution {
public:
    int minCharacters(string a, string b) {
        vector<vector<int>> ans(3, { 0 });
        int n = min(a.size(), b.size());
        if ((a[0] - 'a') < (b[0] - 'a'))
        {
            ans[2][0] = 1;
            ans[1][0] = 1;
        }
        else if ((a[0] - 'a') > (b[0] - 'a'))
        {
            ans[2][0] = 1;
            ans[0][0] = 1;
        }
        else
        {
            ans[0][0] = 1;
            ans[1][0] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if ((a[i] - 'a') < (b[i] - 'a'))
            {
                ans[2].push_back(ans[2][i - 1] + 1);
                ans[1].push_back(ans[1][i - 1] + 1);
                ans[0].push_back(ans[0][i - 1]);
            }
            else if ((a[i] - 'a') > (b[i] - 'a'))
            {
                ans[2].push_back(ans[2][i - 1] + 1);
                ans[1].push_back(ans[1][i - 1]);
                ans[0].push_back(ans[0][i - 1] + 1);

            }
            else
            {
                ans[2].push_back(ans[2][i - 1]);
                ans[1].push_back(ans[1][i - 1] + 1);
                ans[0].push_back(ans[0][i - 1] + 1);
            }
        }
        return min(min(ans[0][n-1], ans[1][n-1]), ans[2][n-1]);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    // string b = "Let's take LeetCode contest";
    // String b = "Let's take LeetCode contest";
    int c = a->minCharacters("aba", "caa");

}