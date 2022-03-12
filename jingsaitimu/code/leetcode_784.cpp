#include "headl.h" 
class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        get(s,0);
        return ans;
    }
    void get(string s, int loc)
    {
        if (loc == s.size() )
        {
            ans.push_back(s);
            return ;
        }
        if ( isalpha(s[loc]))
        {
            s[loc] = tolower(s[loc]);
            get(s,loc+1);
            s[loc] = toupper(s[loc]);
            get(s,loc + 1);
        }
        else
        {
            get(s,loc+1);
        }
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  a->letterCasePermutation("C");
  
}
