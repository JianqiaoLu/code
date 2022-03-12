#include "headl.h" 
class Solution {
public:
    vector<vector<int>> ans;
    void get(vector<int>& nums, int first, int len)
    {
      if (first == (len - 1))
      {
        ans.push_back(nums);
      }
      for (int i = first; i < len ; i++)
      {
        swap(nums[first], nums[i]);
        get(nums, first + 1, len);
        swap(nums[first], nums[i]);
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      get(nums,0, nums.size());
      return ans;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  vector<int> b = {1,2,3};
  a->permute(b);
  
}
