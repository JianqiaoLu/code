#include "headl.h" 
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<pair<int, int>> change = { pair<int,int>(-1,0), pair<int,int>(0,1),pair<int,int>(1,0), pair<int,int>(0,-1) };
        // map<pair<int, int>, bool> visited;
        int r = grid.size();
        int c= grid[0].size();
        int visited[r][c] ;
        for (int i = 0; i < r; i ++)
        {
            for (int j = 0; j < c; j ++)
            {
                visited[i][j]=0;
            }
        }
        vector<pair<int, int>> ans;
        queue<pair<int, int>> dl;
        dl.push(pair<int, int>(row, col));
        while (!dl.empty())
        {

            pair<int, int> op = dl.front();
            visited[op.first][op.second] = 1;
            dl.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = op.first + change[i].first;
                int nc = op.second + change[i].second;
                pair<int, int> np(nr, nc);
                int flag = 0;
                if (valid(np, grid))
                {
                    if (visited[np.first][np.second])
                    {
                        continue;
                    }
                    if (grid[np.first][np.second] == grid[op.first][op.second])
                    {
                        dl.push(np);
                    }
                    else
                    {
                        flag = 1;
                    }

                }
                else
                {
                    flag = 1;
                }

                if (flag)

                {
                    ans.push_back(op);
                }
            }

        }
        for (int i = 0; i < ans.size(); i++)
        {
            grid[ans[i].first][ans[i].second] = color;
        }
        return grid;
    }
    bool valid(pair<int, int> p, vector<vector<int>>& grid)
    {
        return (p.first >= 0) and (p.first < grid.size()) and (p.second >= 0) and (p.second < grid[0].size());
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

    vector<vector<int>> aaa{ {1,1},{1,2} };
    vector<vector<int>> ans1 = a->colorBorder(aaa, 0,0,3);
    int aa= 1;
}


