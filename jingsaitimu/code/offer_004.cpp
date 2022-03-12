#include "headl.h" 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l  = 0, r = 2;
        while (r < nums.size())
        {
            int m = l + (r - l) / 2;
            if (nums[m] == nums[r] and nums[m] != nums[l]) return nums[l];
            else if (nums[m] == nums[l] and nums[m] != nums[r]) return nums[r];
            l = r + 1;
            r = l + 2;
        }
        return nums[l];
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
