#include "headl.h" 

class Solution {
public:
     static bool compare(const vector<int>& odd1, const vector<int>& odd2)
    {
        if (odd1[1] != odd2[1])   return (odd1[1] < odd2[1]);
        else return (odd1[0] < odd2[0]);

    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        int ans = 1;
        vector<int> opt = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= opt[1])
            {
               ans ++ ;
               opt = intervals[i];
            }
        }
        return intervals.size() - ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<vector<int>> b = {{1,2},{2,3},{3,4},{1,3}};
    Solution* a = new Solution();
    a->eraseOverlapIntervals(b);

}
