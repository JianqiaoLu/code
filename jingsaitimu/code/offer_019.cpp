#include "headl.h" 
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size(), l = 0, ch = 1, r = n - 1;
        while (l  < r)
        {
            if (s[l]!= s[r])
            {
                return get(s,l,r-1) or get(s,l+1, r);
            }
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
    bool get(string s, int l, int r)
    {
        while (l<r)
        {
            if (s[l] != s[r])  return false;
            else 
            {
                 l++;
                 r--;
            }
        }
        return true;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");

}
