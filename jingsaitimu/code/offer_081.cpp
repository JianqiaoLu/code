#include "headl.h" 
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis;
    vector<int> candi;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        candi = candidates;
        for (int i = 0; i < candi.size(); i++)
        {
            vis.push_back(candi[i]);
            get(i, target - candi[i]);
            vis.pop_back();
        }
        return ans;
    }
    void get(int k, int target)
    {
        if (target < 0)  return;
        else if (target == 0)
        {
            ans.push_back(vis);
            return;
        }
        for (int i = k; i < candi.size(); i++)
        {
            vis.push_back(candi[i]);
            get(i, target - candi[i]);
            vis.pop_back();
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
