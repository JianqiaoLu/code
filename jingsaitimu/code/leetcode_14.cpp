#include "headl.h" 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return get(strs, 0, strs.size()- 1);
    }
    string get(vector<string> strs, int l , int r)
    {
        if(l == r) return strs[l];
        else
        {
            int m = l + (r - l) /2;
            string a1 = get(strs, l, m);
            string a2 = get(strs, m+1, r);
            if(a1.empty() or a2.empty()) return "";
            else
            {
                int l1 = 0, l2 = 0;
                while (l1 < a1.size() and l2< a2.size())
                {
                    if (a1[l1] != a2[l2])
                    {
                        if (l1 == 0)
                        {
                            return "";
                        }
                        else
                        {
                            return a1.substr(0,l1-1);
                        }
                    }
                    l1 ++ ;
                    l2 ++;
                }
                if(a1.size() < a2.size()) return a1;
                else return a2;
            }
        }
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
