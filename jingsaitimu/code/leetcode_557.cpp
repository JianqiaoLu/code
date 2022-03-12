#include "headl.h" 
#include "string.h"

class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        while (r < s.size())
        {
            if (s[r] == ' ')
            {
                for (int i = 0; i < (r - l) / 2; i++)
                {
                    swap(s[l + i], s[r - 1- i]);
                }
                l = r + 1;
            }
            r++;
        }
        for (int i = 0; i < (r - l) / 2; i++)
        {
            swap(s[l + i], s[r - 1- i]);
        }
        return s;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    string b = "Let's take LeetCode contest";
    // String b = "Let's take LeetCode contest";
    a->reverseWords(b);

}