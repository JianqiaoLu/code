#include "headl.h" 

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int j = -1,k =-1;
        bool same = false;
        int c[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            if ( ++ c[s[i] - 'a']  == 2)
            {
                same =true;
            }
            if (s[i] != goal[i])
            {
                if (j == -1)
                {
                    j = i;
                }
                else 
                {
                    k  = i;
                    swap(s[j],s[i]);
                    if (s == goal)
                    {
                        return true;
                    }
                    return false;
                }
            }
            
        }
        if (same and (j == -1 and k == -1))
        {
            return true;
        }
        return false;
        
        

    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
    Solution* a = new Solution();
    bool ans1 = a->buddyStrings("aa","aa");
}
   