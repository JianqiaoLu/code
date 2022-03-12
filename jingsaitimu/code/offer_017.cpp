#include "headl.h" 
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, ns = s.size(), nt = t.size(), numt = 0;
        string ans = "";

        if (ns < nt) return "";
        map<char, int> a, b, c;

        for (int i = 0; i < nt; i++)
        {
            if (a.count(t[i])) a[t[i]]  ++;
            else a[t[i]] = 1;
            numt++;
        }
        c = a;
        while (r < ns)
        {
            while (r < ns)
            {
                if (a.count(s[r]))
                {
                    if (b.count(s[r])) b[s[r]]++;
                    else b[s[r]] = 1;
                    if (a[s[r]] > 0)
                    {
                        a[s[r]] --;
                        numt--;
                    }
                }
                if (numt == 0) break;
                r++;
            }
            if (r == ns) break;
            while ((not a.count(s[l]) or (a.count(s[l]) and b[s[l]] > c[s[l]])) and l <= r)
            {
                if (a.count(s[l])) b[s[l]] --;
                l++;
            }
            if (numt == 0) ans = (ans.size()) ? ((ans.size() > (r - l + 1)) ? s.substr(l, r - l + 1) : ans) : s.substr(l, r - l + 1);
            a[s[l]] ++;
            b[s[l]] --;
            numt++;
            l++;
            r++;
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->minWindow("ADOBECODEBANC", "ABC");

}
