#include "headl.h" 
class Solution {
public:
    static bool compare(const vector<int>& odd1, const vector<int>& odd2)
    {
        return (odd1[0] < odd2[0]);

    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans{ {intervals[0]} };
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= ans[ans.size() - 1][1])
            {
                vector<int> a;
                a.push_back(min(ans[ans.size() - 1][0], intervals[i][0]));
                a.push_back(max(ans[ans.size() - 1][1], intervals[i][1]));
                ans[ans.size() - 1] = a;
            }
            else
            {
                ans.push_back(intervals[i]);
            }
            
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
