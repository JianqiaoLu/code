#include "headl.h" 
class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        int  n = nums.size();
        int  evnum  = 0;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] % k) == 0)
            {
                evnum ++;
            }
        }
        long long a = (long long) (evnum - 1) * (evnum) /2;
        long long b =  (long long) ( n- evnum) * evnum;
        return a + b;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
