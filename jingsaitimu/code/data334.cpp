#include "headl.h" 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l = -1, m = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (l != -1 and m != -1 and nums[i] > nums[m]) return true;
            if (l==-1 or nums[i] < nums[l]) 
            {
                l = i;
            }
            else if (m== -1 or nums[i] < nums[m])
            {
                m = i;
            }
        }
        return false;
        
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
