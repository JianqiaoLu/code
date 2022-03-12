#include "headl.h" 
class Solution {
public:
    vector<string> ans;
    string a;
    string b;
    vector<string> restoreIpAddresses(string s) {
        b = s;
        int n = s.size();
        get(0, n, 0);
        return ans;
    }
    void get(int k, int n, int size)
    {
        if (k == n and size == 4)
        {
            a.pop_back();
            ans.push_back(a);
            return;
        }
        else if (size == 4 and k < n)
        {
            return;

        }
        if (b[k] == '0')
        {
            a.push_back('0');
            a.push_back('.');
            get(k + 1, n, size + 1);
        }
        else
        {
            int go = b[k] - '0', loc = k;
            string c = a;
            while (go <= 255 and loc < n)
            {
                for (int i = k; i <= loc; i++)
                {
                    a.push_back(b[k]);
                }
                a.push_back('.');
                loc++;
                get(loc, n, size + 1);
                a = c;
                if (loc == n) break;
                go = go * 10 + (b[loc] - '0');
            }
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    string b = "25525511135";
    a->restoreIpAddresses(b);
}
