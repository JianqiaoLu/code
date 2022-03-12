#include "headl.h" 
class Solution {
public:
    string addBinary(string a, string b) {
        int r1 = a.size() - 1, r2 = b.size() - 1;
        int  to = 0;
        string ans = "";
        while (r1 >= 0 or r2 >= 0)
        {
            int ab = to;
            ab += (r1 >= 0) ? (a[r1] - '0') : 0;
            ab += (r2 >= 0) ? (b[r2] - '0') : 0;
            if (ab > 1)
            {
                ab -= 2;
                to = 1;
            }
            else
            {
                to = 0;
            }
            ans.push_back(ab + '0');
            r1--;
            r2--;
        }
        if (to) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
