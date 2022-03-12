#include "headl.h" 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        get(arr, 0, arr.size() - 1);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
    void get(vector<int>& nums, int l, int h)
    {
        if (l >= h) return;
        int i = l, j = h;
        while (i < j)
        {
            while (nums[i] <= nums[h] and i < j) i++;
            while (nums[j] >= nums[h] and i < j)  j--;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[h]);
        get(nums, l, i - 1);
        get(nums, i + 1, h);
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
