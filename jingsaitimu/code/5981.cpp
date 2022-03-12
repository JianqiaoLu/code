#include "headl.h" 
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> loc;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]) loc.push_back(i);
        }
        int m = loc.size();
        for (int i = 0; i < loc.size(); i++)
        {
            int l, r;
            l = loc[i] - i;
            r = loc.size() - i;
            if (l + r > m) m = l + r;
        }
        if ((nums.size() - loc.size()) > m) m = nums.size() - loc.size();
        if(loc.size() == m) ans.push_back(0);
        for (int i = 0; i < loc.size(); i++)
        {
            if(loc[i] == -11) continue;
            int l, r;
            l = loc[i] - i;
            r = loc.size() - i;
            if (l + r == m) ans.push_back(loc[i]);
        }
        if ((nums.size() - loc.size()) == m) ans.push_back(nums.size() );
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = {0,0,1,0};
    a->maxScoreIndices(b);

}
