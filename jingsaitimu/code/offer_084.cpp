#include "headl.h" 
class Solution {
public:
    vector<int> vis;
    vector<int> nums1;
    vector<int> a;
    stack<int> b;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums1 = nums;
        vis = vector<int>(nums.size(), 0);
        get(0);
        return ans;
    }
    void get(int k)
    {
        if (k == nums1.size())
        {
            ans.push_back(a);
            return;
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if (not vis[i] )
            {
                if (i != 0 and nums1[i] == nums1[i - 1] and not vis[i - 1]) continue;
                a.push_back(nums1[i]);
                b.push(nums1[i]);
                vis[i] = 1;
                get(k + 1);
                a.pop_back();
                b.pop();
                vis[i] = 0;
            }
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
