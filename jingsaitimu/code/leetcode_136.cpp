#include "headl.h" 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ret ;
       for(auto e: nums)  ret ^= e;
       return ret;
       
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
