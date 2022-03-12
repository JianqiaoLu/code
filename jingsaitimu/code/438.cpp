#include "headl.h" 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
        {
            return ;
        }
        
        vector<string> tlist;
        // string t[26] = {"0"};
        string t(26, '0');
        string t2(26, '0');
        vector<int> ans;
        for (int i = 0; i < p.size(); i++)
        {
            t[s[i] - 'a'] = (char)(t[s[i] - 'a'] - '0' + 1 + '0');
            t2[p[i] - 'a'] = (char)(t2[p[i] - 'a'] - '0' + 1 + '0');
        }
        if (t == t2)
        {
            ans.push_back(0);
        }

        tlist.push_back(t);
        for (int i = 1; i < s.size() - p.size() + 1; i++)
        {
            t[s[i - 1] - 'a'] = (char)(t[s[i - 1] - 'a'] - '0' - 1 + '0');
            t[s[i + p.size() - 1] - 'a'] = (char)(t[s[i + p.size() - 1] - 'a'] - '0' + 1 + '0');
            if (t2 == t)
            {
                ans.push_back(i);
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
    vector<int> ans1 = a->findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa");
}

