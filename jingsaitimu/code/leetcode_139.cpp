#include "headl.h" 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> ans(n + 1, false);
        ans[0] = true;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < i; i++)
            {
                if (ans[j])
                {
                    string a = s.substr(j, i - j);
                    for (auto it : wordDict)
                    {
                        if (a == it)
                        {
                            ans[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        return ans[n];

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
