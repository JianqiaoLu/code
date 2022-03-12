#include "headl.h" 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> a = {triangle[0][0]};
        for (int i = 1; i < triangle.size(); i++)
        {
            vector<int> b (triangle[i].size());
            for (int j = 0; j < b.size(); j++)
            {
                if (j == 0) b[j] = a[j];
                else if( j == b.size() - 1) b[j] = a[j-1];
                else b[j] = min(a[j], a[j-1]);
                b[j] += triangle[i][j];
            }
            a = b;
        }
        int ans = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            ans = min(ans, a[i]);
        }
        return ans;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
