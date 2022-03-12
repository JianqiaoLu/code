#include "headl.h" 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int, int> > change = { {-1,0},{+1, 0}, {0,-1}, {0,+1} };
        map<pair<int, int>, int> mm;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0 and !mm.count({ i,j }))
                {

                    map<pair<int, int>, int> mm1;
                    queue<pair<int, int>> bfs;
                    bfs.push({ i,j });
                    mm[{i, j}] = 1;
                    mm1[{i, j}] = 1;
                    while (!bfs.empty())
                    {
                        auto a = bfs.front();
                        bfs.pop();
                        for (int k = 0; k < change.size(); k++)
                        {
                            pair<int, int> nl = { a.first + change[k].first, a.second + change[k].second };
                            if (nl.first >= 0 and nl.first < mat.size() and nl.second >= 0 and nl.second < mat[0].size())
                            {
                                if (mat[nl.first][nl.second] != 0 and mm.count(nl))
                                {
                                    mat[nl.first][nl.second] = min(mat[nl.first][nl.second], mat[a.first][a.second] + 1);
                                }
                                else if (mat[nl.first][nl.second] != 0 and !mm.count(nl))
                                {
                                    mat[nl.first][nl.second] = mat[a.first][a.second] + 1;
                                    mm[nl] = 1;
                                }
                                if(! mm1.count(nl))  
                                {
                                    bfs.push(nl);
                                    mm1[nl] = 1;
                                }
                            }
                        }
                    }

                }
            }
        }
        return mat;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<vector<int>> b = { {0,0,0},{0,1,0},{1,1,1} };
    auto c = a->updateMatrix(b);

}
