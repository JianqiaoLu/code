
#include "headl.h" 

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        map<pair<int, int>, int> mm;
        vector<pair<int, int> > change = { {-1,0},{+1, 0}, {0,-1}, {0,+1} };
        int marea = 0;
        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid[0].size(); x++)
            {
                if (grid[y][x] == 1 and !mm.count({ y,x }))
                {
                    int area = 1;
                    queue<pair<int, int>> ans;
                    ans.push({ y,x });
                    mm[{y, x}] = 1;
                    while (!ans.empty())
                    {
                        pair<int, int> a = ans.front();
                        ans.pop();
                        for (int i = 0; i < change.size(); i++)
                        {
                            pair<int, int> nl = { a.first + change[i].first, a.second + change[i].second };
                            if (nl.first >= 0 and nl.first < grid.size() and nl.second >= 0 and nl.second < grid[0].size())
                            {
                                if (grid[nl.first][nl.second] == 1 and !mm.count(nl))
                                {
                                    ans.push(nl);
                                    mm[nl] = 1;
                                    area++;
                                }
                            }
                        }
                    }
                    marea = max(marea, area);
                }
            }
        }
        return marea;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  vector<vector<int>> b  = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
  Solution* a = new Solution();
  a->maxAreaOfIsland(b);


  
}