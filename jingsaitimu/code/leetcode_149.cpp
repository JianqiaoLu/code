#include "headl.h" 
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

    }
    int gety(int k, vector<int> p, int x )
    {
        return p[1] + (x - p[0]) * k;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
