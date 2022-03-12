#include "headl.h" 
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int num = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }
            num++;
            visited[i] = 1;
            queue<int> dfs;
            dfs.push(i);
            while (!dfs.empty())
            {
                int ci = dfs.front();
                dfs.pop();
                for (int j = 0; j < isConnected[ci].size(); j++)
                {
                    if (j == ci) continue;
                    if (isConnected[ci][j] and (!visited[j]))
                    {
                        dfs.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
        return num;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
