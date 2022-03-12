#include "headl.h" 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> bique(k, 0);
        int l = 0, r = 0;
        for (int i = 0; i < k; i++)
        {
            if (l >= r)
            {
                bique[l] = nums[i];
                l = 0;
                r = 1;
            }
            else
            {
                while (r > l)
                {
                    if (bique[r - 1] < nums[i])
                        r--;
                    else
                    {
                        bique[r] = nums[i];
                        r++;
                        break;
                    }
                }
                if (r == l)
                {
                    bique = vector<int>(k, 0);
                    bique[0] = nums[i];
                    l = 0;
                    r = 1;
                }
            }
        }
        vector<int> ans;
        ans.push_back(bique[0]);
        int l1 = 1, r1 = k;
        while (r1 < nums.size())
        {
            if (nums[l1 - 1] == bique[l])
            {
                l++;
            }
            while (r > l)
            {
                if (bique[r - 1] < nums[r1]) r--;
                else
                {
                    bique[r] = nums[r1];
                    r++;
                    break;
                }
            }
            if (r == l)
            {
                bique = vector<int>(k, 0);
                bique[0] = nums[i];
                l = 0;
                r = 1;
            }
            ans.push_back(bique[0]);
            l1 ++;
            r1++;

        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
