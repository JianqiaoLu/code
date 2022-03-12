#include "headl.h" 
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> ans(questions.size() + 1, 0);
        ans[ans.size() - 1] = questions[questions.size( ) - 1][0];
        for (int i = ans.size() - 2; i > 0;i--)
        {
            if (i + 1 + questions[i-1][1]< ans.size())
            {
                ans[i] = max(ans[i + 1], questions[i - 1][0] + ans[i + questions[i-1][i]]);
            }
            else
            {
                ans[i] = max(ans[i + 1], ans[ans.size() -1]);
            }
            
        }
        return ans[1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<vector<int>> b = {{1, 1},{2,2},{3,3},{4,4}, {5,5}};
    a->mostPoints(b);

}
