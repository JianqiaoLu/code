#include "headl.h" 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0, sum = nums[0], n = nums.size(), ans = 0;
        while (r < n)
        {

            if (sum == k) 
            { 
                ans++;
                r ++;
                if(r == n) break;
                sum += nums[r];
            }
            else if (sum < k)
            {
                r++;
                sum += nums[r];
            }
            else
            {
                sum -= nums[l];
                l++;
            }
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<int> b = {1};
    Solution* a = new Solution();
    a->subarraySum(b,0);

}
