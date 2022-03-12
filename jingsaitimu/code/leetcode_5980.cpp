#include "headl.h" 
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0;
        while( i <= (s.size() - k) and (s.size() >= k))
        {
            ans.push_back(s.substr(i, k));
            i = i + k;
        }
        if(i !=  (s.size() ))
        {
            ans.push_back(s.substr(i));
        }
        for (int i = ans[ans.size()  - 1].size(); i < k; i++)
        {
            ans[ans.size() -1 ].push_back(fill);
        }
        return ans;
        
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  a->divideString("bgycymgbblobvpdf", 67,'x');
  
}

