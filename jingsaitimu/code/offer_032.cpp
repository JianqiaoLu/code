#include "headl.h" 
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a, b;
        a = get(s);
        b = get(t);
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i]) return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])     return true;
        }
        return false;
    }
    vector<int> get(string s)
    {
        vector<int> a(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            a[s[i] - 'a'] ++;
        }
        return a;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
