#include "headl.h" 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<pair<string, int>> ans;
        pair<string, int> a(s.substr(0,1),1);
        ans.push_back(a);
        for (int i = 1; i < s.size(); i ++)
        {  
            pair<string, int> b;
            int position = ans[i-1].first.find(s[i]);
            if( position == ans[i-1].first.npos)
            {
                ans[i-1].first.push_back(s[i]);
                b.first = ans[i-1].first;
            }
            else
            {
                string aa =ans[i-1].first.substr(position+ 1); 
                aa.push_back(s[i]);
                b.first = aa;
            }
            int ll = b.first.size();
            b.second = max(ans[i-1].second, ll);
            ans.push_back(b);
        }
        return ans[s.size() -1].second;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
    Solution* a = new Solution();
 string b = "Let's take LeetCode contest";
    // String b = "Let's take LeetCode contest";
    int c = a->lengthOfLongestSubstring(b);
   
    int d;
}