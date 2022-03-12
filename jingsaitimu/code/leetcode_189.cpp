#include "headl.h" 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    if (k > nums.size())
    {
        k  =  k  % nums.size();
    }
    int p = nums.size()  - k ; 
    vector<int> ans ;
    for(int i = 0 ;  i< k ; i ++)
    {
        ans.push_back(nums[p + i]);
    }
    for (int i = 0 ; i < nums.size() - k; i ++ )
    {
        ans.push_back(nums[i]);
    };
    nums = ans;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
   
}
