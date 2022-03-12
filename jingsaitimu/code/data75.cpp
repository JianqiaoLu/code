#include "headl.h" 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r= 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i]  == 0) 
            { 
                swap(nums[l++ ], nums[i]);
                r ++ ;
            }
            else if (nums[i] == 1) swap(nums[r ++], nums[i]);
            else i ++;
        }
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
