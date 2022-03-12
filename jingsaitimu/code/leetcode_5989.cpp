#include "headl.h" 
class Solution {
public:
    int countElements(vector<int>& nums) {
        int prev = nums[nums.size() - 1];
        int ans = 0;
        int dup = 1;
        int i = 0;
        for (; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                dup++;
            }
            else if (((prev < nums[i]) and (nums[i]< nums[i + 1])) or ((prev > nums[i]) and (nums[i] > nums[i + 1])))
            {
                ans = ans + dup;
                dup = 1;
                prev = nums[i];
            }
            else
            {
                prev = nums[i];
            }
            
        }
        if(((prev < nums[i]) and (nums[i]< nums[0])) or ((prev > nums[i]) and (nums[i] > nums[0])))
        {
            ans= ans + dup;
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<int> b = {-3,3,3,90};
    Solution* a = new Solution();
    int ans = a->countElements(b);
    int c =1;

    

}
