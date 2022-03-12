#include "headl.h" 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> a = { 0,0 };
        vector<int> b = { 0,0 };
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (a[0] > a[1]) a[1]++;
            }
            else if (s[i] == '(')
            {
                a[0] ++;
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (b[0] > b[1])
                {
                    b[1] ++;
                    ans.push_back(s[i]);
                }
            }
            else if (s[i] == '(')
            {
                if (b[0] < a[1])
                {
                    ans.push_back(s[i]);
                    b[0] ++;
                }
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
