#include "headl.h" 
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = left;
        for (int i = left + 1; i <= right; i++)
        {
            ans = (ans & i);
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
