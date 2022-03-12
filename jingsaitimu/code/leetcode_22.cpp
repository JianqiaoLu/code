#include "headl.h" 
class Solution {
public:
    vector<string> ans;
    string a;
    vector<string> generateParenthesis(int n) {
        get(0, 0,0,2 * n);
    }
    void get(int k, int l, int r, int final)
    {
        if (k == final)
        {
            ans.push_back(a);
            return;
        }
        if (r < l)
        {
            a.push_back(')');
            get(k + 1, l, r + 1, final);
            a.pop_back();
            if (l < final / 2)
            {
                a.push_back('(');
                get(k + 1, l + 1, r, final);
                a.pop_back();
            }
        }
        else
        {
            a.push_back('(');
            get(k + 1, l + 1, r, final);
            a.pop_back();
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
