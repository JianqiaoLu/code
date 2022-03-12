#include "headl.h" 
class Solution {
public:
    bool isPalindrome(string s) {
        string b;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isalpha(s[i])) b.push_back(tolower( s[i]));
            else if (isdigit(s[i])) b.push_back(s[i]);
        }
        int n1 = b.size();
        for (int i = 0; i < n1 / 2; i++)
        {
            if (b[i] != b[n1 - 1 - i]) return false;
        }
        return true;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
