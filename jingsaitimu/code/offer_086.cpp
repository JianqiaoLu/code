#include "headl.h" 
class Solution {
public:
    vector<vector<bool>> is;
    vector<string> a;
    vector<vector<string>> ans;
    string b;
    vector<vector<string>> partition(string s) {
        b = s;
        int n = s.size();
        is = vector< vector<bool> >(n, vector<bool>(n, true));
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                is[j][i] = (s[i] == s[j]) and is[j + 1][i - 1];
            }
        }
        get(n,0);
        return ans;
    }
    void get(int n, int k)
    {
        if (k == n)
        {
            ans.push_back(a);
            return;
        }
        else
        {
            for (int i = k; i < n; i++)
            {
                if (is[k][i])
                {
                    a.push_back(b.substr(k, i - k + 1));
                    get(n,i+1);
                    a.pop_back();
                }
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
