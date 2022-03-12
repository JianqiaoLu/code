#include "headl.h" 
class Solution {
public:
    vector<string> cellsInRange(string s) {
        int c1 = s[0] - 'A';
        int r1 = s[1] - '0';
        int c2 = s[3] - 'A';
        int r2 = s[4] - '0';
        vector<string> ans;
        for (int i = c1; i <= c2; i++)
        {
            for (int j = r1; j <= r2; j++)
            {
                string a;
                a.push_back((i + 'A'));
                a.push_back((j + '0'));
                ans.push_back(a);
            }
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
