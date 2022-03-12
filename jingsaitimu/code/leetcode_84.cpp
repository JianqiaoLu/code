#include "headl.h" 
class Solution {
public:
    stack<int> a;
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (a.empty()) a.push(i);
            else
            {
                int go = heights[a.top()];
                if (go <= heights[i]) a.push(i);
                while (not a.empty() and heights[a.top()] > heights[i])
                {
                    go = heights[a.top()];
                    a.pop();
                    ans = max(ans, go * (i - ((a.empty()) ? -1 : a.top()) - 1));
                }
                a.push(i);
            }
        }
        while (not a.empty())
        {
            int go = heights[a.top()];
            a.pop();
            int go2 = go * (heights.size() - ((a.empty()) ? -1 : a.top()) - 1);
            ans = max(ans, go2);
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 2,1,5,6,2,3 };
    a->largestRectangleArea(b);

}
