#include "headl.h"
#include "queue"
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> change = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        vector<vector<int>> len(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        if (grid[0][0])
        {
            return -1;
        }
        len[0][0] = 1;
        queue<vector<int>> bfs;
        bfs.push({0, 0});
        visited[0][0] = 1;
        while (!bfs.empty())
        {
            vector<int> loc = bfs.front();
            bfs.pop();
            for (int i = 0; i < change.size(); i++)
            {
                vector<int> a = {loc[0] + change[i][0], loc[1] + change[i][1]};
                if (a[0] >= 0 and a[0] < n and a[1] >= 0 and a[1] < m and grid[a[0]][a[1]])
                {
                    if (!visited[a[0]][a[1]])
                    {

                        len[a[0]][a[1]] = len[loc[0]][loc[1]] + 1;
                        visited[a[0]][a[1]] = 1;
                        // if (a[0] == n - 1 and a[1] == m - 1)
                        // {
                        // return len[a[0]][a[1]];
                        // }
                        bfs.push(a);
                    }
                    else
                    {
                        if (len[loc[0]][loc[1]] + 1 < len[a[0]][a[1]])
                        {
                            len[a[0]][a[1]] = len[loc[0]][loc[1]] + 1;
                            bfs.push(a);
                        }
                    }
                }
            }
        }
        return len[n - 1][m - 1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution *a = new Solution();
}
