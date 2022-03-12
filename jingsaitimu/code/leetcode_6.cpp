#include "headl.h" 
class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        for (int i = 1; i <= numRows; i++)
        {
            int loc = i, k = 1;
            if (i == 1)
            {
                while (loc <= s.size())
                {
                    ans.push_back(s[loc - 1]);
                    loc += 2 * (numRows - i - 1) + 2;
                }
            }
            else if (i == numRows)
            {
                while (loc <= s.size())
                {
                    ans.push_back(s[loc - 1]);
                    loc += 2 * (i - 2) + 2;
                }
            }
            else
            {
                while (loc <= s.size())
                {
                    ans.push_back(s[loc - 1]);
                    if (k % 2 == 1)
                    {
                        loc += 2 * (numRows - i - 1) + 2;
                    }
                    else
                    {
                        loc += 2 * (i - 1 - 1) + 2;
                    }
                    k++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
