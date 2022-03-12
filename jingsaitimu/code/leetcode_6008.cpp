#include "headl.h" 
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            int l = 0, r = 0;
            while (r < pref.size())
            {
                if (words[i][l] != pref[r])
                {
                    break;
                }
                l ++ ;
                r ++;
            }
            if (r == pref.size())
            {
                ans ++;
            }
        }
        return ans;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
