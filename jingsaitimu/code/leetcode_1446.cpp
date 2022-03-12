#include "headl.h" 
class Solution {
public:
    int maxPower(string s) {
        int d[s.size()][2] ;
        d[0][1] = 1;
        d[0][0] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            d[i][0] = d[i-1][0];
            if (s[i] == s[i - 1])
            {
                d[i][1] = d[i - 1][1] + 1;
                d[i][0] = max(d[i][0], d[i][1]);
            }
            else
            {
                d[i][1] = 1;
            }
        }
        return d[s.size()-1][0];
    }
};
#include "headl.h" 
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    // vector<int> aaa{ 1,2,3,5 };
    int ans1 = a->maxPower("leetcode");
    int b = 1;

}
