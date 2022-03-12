#include "headl.h" 


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int loc ;
       int l = 0;
       int r = nums.size() - 1;
       int ans = -1;
       while(l <= r)
       {
           int mid = l + (r - l)/2;
           if ( nums[mid] >= 0){
               r = mid - 1;
               ans  = mid;
           }
           else{
               l = mid + 1;
           }
       }
       int lp = ans - 1;
       int rp = ans;
       vector<int> ll;
       while(lp >= 0 and rp <= nums.size() -1 )
       {
           if(nums[lp] * nums[lp] > nums[rp] * nums[rp])
           {
               ll.push_back(nums[rp]*nums[rp]);
               rp ++;
           }
           else{
                ll.push_back(nums[lp]*nums[rp]);
                lp --;
           }
       }
       if(lp < 0 )
       {
           for(int j = rp;  j < nums.size() -1 ; j ++ )
           {
               ll.push_back(nums[j]*nums[j]);
           }
       }
       if ( rp > nums.size() - 1)
       {
           for(int i = lp ; i >= 0 ;  i -- )
           {
               ll.push_back(nums[i]*nums[i]);
           }
       }
       return ll;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
    Solution* a = new Solution();
    vector<int> b = {-4,-1,0,3,10};
    a->sortedSquares(b);
   
}