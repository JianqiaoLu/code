#include "headl.h" 
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n ;
        if (num1.size() > num2.size())
        {
            n = num1.size() - num2.size();
            for (int i = 0; i < n; i++)
            {
                num2 = "0" + num2;
            }
        }
        else
        {
            n = num2.size() - num1.size();
            for (int i = 0; i < n; i++)
            {
                num1 = "0" + num1;
            }
        }
        int a = 0;
        string ans = "";
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int b = num1[i] - '0' + num2[i] - '0' + a;
            if (b >= 10)
            {
                a = 1;
                b = b % 10;
            }
            else a = 0;
            ans.push_back('0' + b);
        }
        if (a)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->addStrings("9133", "0");

}
