#include "headl.h" 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<int> a;
        a.push(-1);
        a.push(0);
        for (int i = 1; i < n; i++)
        {
            int j = a.top();
            while (heights[i] < j and j != -1)
            {
                a.pop();
                ans = max(ans, heights[j] * (i - j - 1));
                j = a.top();
            }
            a.push(i);
        }
        while (a.top() != -1)
        {
            int j = a.top();
            a.pop();
            ans = max(ans, heights[j] * (n - a.top() - 1));
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
