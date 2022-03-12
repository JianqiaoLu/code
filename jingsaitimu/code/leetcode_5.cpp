#include "headl.h" 
class Solution {
public:
    pair<int,int> expander(string s, int l, int r )
    {
        while(l>=0 and r<= s.size() - 1 and s[l] == s[r])
        {l --;
         r ++;}
         return pair<int,int> (++l,--r);
    }
    string longestPalindrome(string s) {
        int st = 0;
        int en = 0;
        for(int i = 0; i < s.size()-1; i ++)
        {
            auto[left1, right1] = expander(s,i , i);
             auto[left2, right2] = expander(s,i, i + 1);
             if((right1 - left1) > (en -st))
             {
                 en = right1;
                 st= left1;
             }
             if((right2 - left2) > (en -st))
             {
                 en = right2;
                 st= left2;
             }
         }
        return s.substr(st, (en - st  +1));
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
    Solution* a = new Solution();
    string ans1 = a->longestPalindrome("babad");
    int b = 1;
   
}
