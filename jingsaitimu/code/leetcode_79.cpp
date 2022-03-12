#include "headl.h" 
#include "headl.h" 
class Solution {
public:
    vector<vector<int>> change = { {-1,0}, {1,0}, {0,1}, { 0, -1} };
    bool bfs(vector<vector<char>> board, vector<int> xy, vector<char> word, int loc, vector<vector<int>>& vis)
    {
        if (loc == word.size()) return true;
        for (int i = 0; i < change.size(); i++)
        {
            vector<int> nxy = { xy[0] + change[i][0],xy[1] + change[i][1] };
            if (nxy[0] < 0 or nxy[0] >= board.size() or nxy[1] < 0 or nxy[1] >= board[0].size() or vis[nxy[0]][nxy[1]] or board[nxy[0]][nxy[1]] != word[loc])
            {
                continue;
            }
            vis[nxy[0]][nxy[1]] = 1;
            if (bfs(board, nxy, word, loc + 1, vis)) return true;
        }
        vis[xy[0]][xy[1]] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<char> aa;
        for (int i = 0; i < word.size(); i++)
        {
            aa.push_back(word[i]);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != aa[0]) continue;
                vector<vector<int>> vis(board.size(), vector<int>(board[0].size()));
                vis[i][j] = 1;
                if (bfs(board, { i,j }, aa, 1, vis)) return true;
            }
        }
        return false;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<vector<char>> b = { {'a','b'},{'c','d'} };
    bool ans = a->exist(b, "cdba");
    int c = 1;
}
