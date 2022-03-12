#include "headl.h" 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        string b;
        vector<int> ans;
        for (string i : words) b += i;
        int n1 = s.size(), n2 = b.size();
        if (n1 < n2) return ans;
        vector<int> a1, a2;
        a1 = get(s.substr(0, n2));
        a2 = get(b);
        int cur = n2 - 1;
        bool flag;
        for (int i = 0; i < a1.size(); i++)
        {
            flag = true;
            if (a1[i] != a2[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans.push_back(cur - b.size() + 1);
        }
        cur++;
        while (cur < n1)
        {
            a1[s[cur - n2] - 'a']--;
            a1[s[cur] - 'a'] ++;
            flag = true;
            for (int i = 0; i < a1.size(); i++)
            {
                if (a1[i] != a2[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans.push_back(cur - b.size() + 1);
            }
            cur++;
        }
        return ans;
    }
    vector<int> get(string s)
    {
        vector<int> ans(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            ans[s[i] - 'a'] ++;
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
