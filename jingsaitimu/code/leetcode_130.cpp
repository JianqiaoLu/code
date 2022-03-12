#include "headl.h"
#include <queue>
class Solution
{
public:
    vector<vector<int>> change = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>> &board)
    {
        int l = 0, r = board[0].size(), lo = 0, hi = board.size();
        for (int x = l; x < r; x++)
        {
            int y = lo;
            if (board[y][x] == 'O')
            {
                board[y][x] = '1';
                queue<vector<int>> dfs;
                dfs.push({y, x});
                while (!dfs.empty())
                {
                    vector<int> loc = dfs.front();
                    dfs.pop();
                    for (int i = 0; i < change.size(); i++)
                    {
                        vector<int> tmp = {loc[0] + change[i][0], loc[1] + change[i][1]};
                        if (tmp[0] >= 0 and tmp[0] < board.size() and tmp[1] >= 0 and tmp[1] < board[0].size() and board[tmp[0]][tmp[1]] == 'O')
                        {
                            board[tmp[0]][tmp[1]] = '1';
                            dfs.push(tmp);
                        }
                    }
                }
            }
        }
        for (int y = lo + 1; y < hi; y++)
        {
            int x = r - 1;
            if (board[y][x] == 'O')
            {
                board[y][x] = '1';
                queue<vector<int>> dfs;
                dfs.push({y, x});
                while (!dfs.empty())
                {
                    vector<int> loc = dfs.front();
                    dfs.pop();
                    for (int i = 0; i < change.size(); i++)
                    {
                        vector<int> tmp = {loc[0] + change[i][0], loc[1] + change[i][1]};
                        if (tmp[0] >= 0 and tmp[0] < board.size() and tmp[1] >= 0 and tmp[1] < board[0].size() and board[tmp[0]][tmp[1]] == 'O')
                        {
                            board[tmp[0]][tmp[1]] = '1';
                            dfs.push(tmp);
                        }
                    }
                }
            }
        }
        for (int x = r - 2; x >= l; x--)
        {
            int y = hi - 1;
            if (board[y][x] == 'O')
            {
                board[y][x] = '1';
                queue<vector<int>> dfs;
                dfs.push({y, x});
                while (!dfs.empty())
                {
                    vector<int> loc = dfs.front();
                    dfs.pop();
                    for (int i = 0; i < change.size(); i++)
                    {
                        vector<int> tmp = {loc[0] + change[i][0], loc[1] + change[i][1]};
                        if (tmp[0] >= 0 and tmp[0] < board.size() and tmp[1] >= 0 and tmp[1] < board[0].size() and board[tmp[0]][tmp[1]] == 'O')
                        {
                            board[tmp[0]][tmp[1]] = '1';
                            dfs.push(tmp);
                        }
                    }
                }
            }
        }
        for (int y = hi - 2; y >= lo; y--)
        {
            int x = l;
            if (board[y][x] == 'O')
            {
                board[y][x] = '1';
                queue<vector<int>> dfs;
                dfs.push({y, x});
                while (!dfs.empty())
                {
                    auto loc = dfs.front();
                    dfs.pop();
                    for (int i = 0; i < change.size(); i++)
                    {
                        vector<int> tmp = {loc[0] + change[i][0], loc[1] + change[i][1]};
                        if (tmp[0] >= 0 and tmp[0] < board.size() and tmp[1] >= 0 and tmp[1] < board[0].size() and board[tmp[0]][tmp[1]] == 'O')
                        {
                            board[tmp[0]][tmp[1]] = '1';
                            dfs.push(tmp);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
                {

            }
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution *a = new Solution();
    vector<vector<char>> b = {{'X', 'X', 'X', 'X'},
                              {'X', 'O', 'O', 'X'},
                              {'X', 'X', 'O', 'X'},
                              {'X', 'O', 'X', 'X'}};
    a->solve(b);
}
