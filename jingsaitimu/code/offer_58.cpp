#include "headl.h" 
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = n - 1;
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ' and l == i) l--;
            else if (s[i] == ' ' and l != i)
            {
                ans = ans + " " + s.substr(i + 1, l - i);
                l = i - 1;
            }
        }
        if (l>= 0)
        {
          ans = ans + " " + s.substr(0,l + 1);
        }
        if (not ans.empty())
        {
            ans = ans.substr(1);
        }
        return ans;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->reverseWords("a good   example");

}
