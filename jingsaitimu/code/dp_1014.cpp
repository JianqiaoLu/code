#include "headl.h" 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), m = values[0] + 0 - 1 + values[1];
        vector<int> ans(n, 0);
        ans[0] = values[0] + 0;
        for (int i = 1; i < n; i++)
        {
            m = max(m, values[i] - i + ans[i - 1]);
            ans[i] = max(ans[i - 1], values[i] + i);
        }
        return m;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
