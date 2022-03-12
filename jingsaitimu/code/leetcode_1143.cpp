#include "headl.h" 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            if (text1[0] == text2[i] or (i > 0 and ans[0][i - 1]))  ans[0][i] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (text2[0] == text1[i] or (i > 0 and ans[i - 1][0]))  ans[i][0] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                int k = 0;
                for (int z = 0; z <= i; z++)
                {
                    if (text1[z] == text2[j])
                    {
                        if(z== 0) k = max(1,k);
                        else  k = max(ans[z-1][j - 1] + 1, k);
                    }
                }
                k = max(ans[i][j - 1], k);
                ans[i][j] = k;
            }
        }
        return ans[n - 1][m - 1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->longestCommonSubsequence("abcba", "abcbcba");

}
