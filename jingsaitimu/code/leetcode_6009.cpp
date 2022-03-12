#include "headl.h" 
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a , b;
        a = get(s);
        b = get(t);
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            ans += abs(a[i] - b[i]);
        }
        return ans;
    }
    vector<int> get(string s)
    {
        vector<int> ans (26,0);
        for (int i = 0; i < s.size(); i++)
        {
            ans[s[i] - 'a'] ++;
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
