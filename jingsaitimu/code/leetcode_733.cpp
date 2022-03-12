#include "headl.h" 
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int p = image[sr][sc];
        if(p == newColor)
        {
            return image;
        }
        image[sr][sc] = newColor;
        queue<pair<int, int>> ans;
        vector<pair<int, int> > change = { {-1,0},{+1, 0}, {0,-1}, {0,+1} };
        ans.push({ sr,sc });
        int xi = image[0].size();
        int yi = image.size();
        while (!ans.empty())
        {
            pair<int, int> a = ans.front();
            ans.pop();
            for (int i = 0; i < change.size(); i++)
            {
                pair<int, int> nl = { a.first + change[i].first, a.second + change[i].second };
                if (get(nl.first, nl.second, yi, xi) )
                {
                    if (image[nl.first][nl.second] == p)
                    {
                        ans.push(nl);
                        image[nl.first][nl.second] = newColor;                    
                    }
                }
            }
        }
        return image;
    }
    bool get(int x, int y, int xi, int yi)
    {
        return (x >= 0 and x < xi and y >= 0 and y < yi);
    }
};

int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<vector<int>> c{ {0,0,0},{0,0,0}};
    auto b = a->floodFill(c, 1, 0, 2);
    int ccc=1;
}