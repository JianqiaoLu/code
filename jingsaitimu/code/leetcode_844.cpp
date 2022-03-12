#include "headl.h" 
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, t1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '#') s1.push(s[i]);
            else
            {
                if (!s1.empty()) s1.pop();
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (s[i] != '#') t1.push(s[i]);
            else
            {
                if (!t1.empty()) t1.pop();
            }
        }
        while (!s1.empty() and !t1.empty())
        {
            if (s1.top() != t1.top()) return false;
            s1.pop();
            t1.pop();
        }
        if ((!s1.empty() and t1.empty()) or (!t1.empty() and s1.empty())) return false;
        else return true;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
