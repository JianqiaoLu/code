#include "headl.h" 
class Solution {
public:
    vector<vector<int>> change = { {0,1}, {1, 0} };
    int movingCount(int m, int n, int k) {
        queue<vector<int>> a;
        vector<vector<int>> visited(m, vector<int>(n));
        visited[0][0] = 1;
        int ans = 1;
        a.push({ 0,0 });
        while (!a.empty())
        {
            vector<int> pre = a.front();
            a.pop();
            for (int i = 0; i < change.size(); i++)
            {
                vector<int> loc = { pre[0] + change[i][0], pre[1] + change[i][1] };
                if (loc[0] >= 0 and loc[0] < m and loc[1] >= 0 and loc[1] < n and valid(loc, k) and not visited[loc[0]][loc[1]])
                {
                    a.push(loc);
                    visited[loc[0]][loc[1]] = 1;
                    ans ++;
                }
            }
        }
        return ans;
    }
    bool valid(vector<int> loc, int k)
    {
        int ans = 0;
        while (loc[0] != 0)
        {
            ans += loc[0] % 10;
            loc[0] = loc[0] / 10;
        }
        while (loc[1] != 0)
        {
            ans += loc[1] % 10;
            loc[1] = loc[1] / 10;
        }
        return (ans <= k);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
}
