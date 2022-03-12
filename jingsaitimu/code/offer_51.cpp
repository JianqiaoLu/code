#include "headl.h" 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return get(nums,0, nums.size() - 1);
    }
    int get(vector<int>& nums, int l, int r)
    {
        if (l >= r) return  0;
        int m = l + (r - l) / 2;
        int a1 = get(nums, l, m), a2 = get(nums, m + 1, r), a3 = 0;
        int rp = r;
        for (int i = m; i >= l; i--)
        {
            while (nums[rp] >= nums[i] and rp >= m + 1) rp--;
            a3 += rp - m;
        }
        sort(nums.begin() + l, nums.begin() + r + 1);
        // int l1 = 1, l2 = m + 1;
        // vector<int> a;
        // while (l1 <= m or l2 <= r)
        // {
            // if (nums[l1] < nums[l2])
            // {
                // a.push_back(nums[l1]);
                // l1++;
            // }
            // else
            // {
                // a.push_back(nums[l2]);
                // l2++;
            // }
        // }
        // while (l1 <= m)
        // {
            // a.push_back(nums[l1]);
            // l1++;
        // }
        // while (l2 <= r)
        // {
            // a.push_back(nums[l2]);
            // l2++;
        // }
        // for (int i = 0; i < a.size(); i++)
        // {
            // nums[l + i] = a[i];
        // }
        return a1 + a2 + a3;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = {7,5,6,4};
    a->reversePairs(b);

}

