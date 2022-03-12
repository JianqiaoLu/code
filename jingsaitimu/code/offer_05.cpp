#include "headl.h" 


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r)
        {
            int m = l + (r - l) / 2;
            if(nums[m] == l  + (r - l )/2)
            {
                l = m+1;
            }
            else
            {
                r = m;
            }
        }
        if(l == nums.size() - 1)
        {
            if ( nums[l] == nums.size() - 1)
            { return l + 1;}
            else
            { return l;}
        }
        else  return l;
        
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  vector<int> c = {0,1};
  auto b = a->missingNumber(c);
  
}