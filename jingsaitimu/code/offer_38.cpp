#include "headl.h" 
class Solution {
public:
    vector<string> ans;
    string a;
    vector<int> visi;
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        visi = vector<int>(s.size(), 0);
        get(s, 0);
    }
    void get(string s, int k)
    {
        if (k == s.size())
        {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (visi[i] or (i > 0 and visi[i - 1] and s[i] == s[i - 1])) continue;
            else
            {
                visi[i] = 1;
                a.push_back(s[i]);
                get(s, k + 1);
                visi[i] = 0;
                a.pop_back();
            }
        }

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
