#include "headl.h" 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a = get(s1);
        string s3 = s2.substr(0,s1.size());
        vector<int> b = get(s3);
        if(a == b)
            {
                return true;
            }
        for(int i = 1 ; i + s1.size() <= s2.size(); i ++)
        {
            b[s2[i - 1] - 'a'] --;
            b[s2[i + s1.size() -1]  - 'a'] ++;
            if(a == b)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> get(string s)
    {
        vector<int> a(26,0);
        for(int i = 0 ; i < s.size() ; i++)
        {
            a[s[i]-'a'] ++;
        }
        return a;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
   freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
    Solution* a = new Solution();
    string b = "Let's take LeetCode contest";
    // String b = "Let's take LeetCode contest";
    int c = a->checkInclusion("ab","eidbaooo");
   
    int d;
   
}
