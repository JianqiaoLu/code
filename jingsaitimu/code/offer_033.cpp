#include "headl.h" 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mm;
        for (auto i : strs)
        {
            string a = i;
            sort(i.begin(), i.end());
            mm[i].push_back(a);
        }
        vector<vector<string>> ans;
        for (auto it = mm.begin(); it != mm.end(); ++it)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
