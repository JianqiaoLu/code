#include "headl.h" 
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> detect(s.size(), vector<bool>(s.size()));
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= i; j--)
            {
                detect[j][i] = true;
            }

        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                detect[j][i] = detect[j + 1][i - 1] and (s[j] == s[i]);
            }
        }
        int st= 0, en = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (detect[j][i])
                {
                    if((i - j + 1)  > (en - st+ 1))
                    {
                        st = j;
                        en= i;
                    }
                }
            }
        }
        return s.substr(st, en - st + 1);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->longestPalindrome("babad");

}
