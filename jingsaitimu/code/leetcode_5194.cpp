#include "headl.h" 
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        vector<vector<int>> ans (target+1,vector<int>(maxDoubles + 1));

        for (int i = 2; i < ans.size(); i++)
        {
            for (int j = 0; j <= maxDoubles; j++)
            {
                if (i%2 == 0 and j)
                {
                   ans[i][j] = min(ans[i-1][j] + 1, ans[i/2][j-1] + 1);
                }
                else
                {
                    ans[i][j]= ans[i-1][j] + 1;
                }
            }
        }
        return ans[target][maxDoubles];
    }

};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  a->minMoves(5,0);
  
}

