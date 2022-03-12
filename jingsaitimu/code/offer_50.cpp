#include "headl.h" 
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> ans(26, 0);
        vector<int> loc(26, -1);
        if (s.empty())
        {
            return ' ';
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            ans[s[i] - 'a'] = ans[s[i] - 'a'] + 1;
            loc[s[i] - 'a'] = i;
        }
        int minloc = s.size();
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == 1 and minloc > loc[i])
            {
                minloc = loc[i];
            }
        }
        if (minloc == s.size())
        {
            return ' ';
        }
        else
        {
            return s[minloc];
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->firstUniqChar("cc");

}
