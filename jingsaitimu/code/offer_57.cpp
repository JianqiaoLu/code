#include "headl.h" 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int prev  = n - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > target) return {};
            int l = prev;
            while( l > i )
            {
                if((nums[l] + nums[i]) == target) return {nums[i], nums[l]};
                else if (nums[l] + nums[i] < target ) break;
                l  -- ;
            }
        }
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
}
