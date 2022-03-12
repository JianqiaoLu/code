#include "headl.h" 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> a(26,0),b(26,0);
        int n = s.size();
        for (int i = 0; i < p.size(); i++)
        {
            a[p[i]-'a'] ++;
            b[s[i]-'a'] ++;
        }
        vector<int> ans;
        if (a == b)
        {
            ans.push_back(0);
        }
        for (int i = 1; i <= n - p.size() ; i++)
        {
            b[s[i] - 'a']  --;
            b[s[i + p.size() - 1] - 'a']  ++;
            if (b == a)
            {
                ans.push_back(i);
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
