#include "headl.h" 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> a;
        int n = s.size(), m = 0;
        if(n == 0) return 0;
        vector<int> ans(n, 0);
        ans[0] = 1;
        a[s[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (not a.count(s[i]))
            {
                ans[i] = ans[i-1]  + 1;
            }
            else
            {
                int j = a[s[i]];
                if ((i - 1 - j) >= ans[i - 1]) ans[i] = ans[i - 1] + 1;
                else ans[i] = i - j;
            }
            a[s[i]] = i;
            m = max(m, ans[i]);
        }
        return m;
    }

};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->lengthOfLongestSubstring("pwwkew");

}
