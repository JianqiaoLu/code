#include "headl.h" 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> a;
        vector<int> ans(s.size(), 1);
        for (int i = 1; i < s.size(); i++)
        {
            if (!a.count(s[i]))
            {
                ans[i] = ans[i-1]  +1;
                a[s[i]]  = i;
            }
            else
            {
                if ((i - a[s[i]]) > ans[i-1])
                {
                    ans[i] = ans[i-1] + 1;
                }
                else
                {
                    ans[i] = i  - a[s[i]];
                }
            }
        }
        int m = 1;
        for (int i = 1; i < ans.size(); i++)
        {
            m = max(ans[i], m);
        }
        return m;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
