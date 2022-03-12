#include "headl.h" 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> a;
        for (int i = 0; i < nums.size(); i++)
        {
            a.push(nums[i]);
            if (a.size() > k) a.pop();
        }
        return a.top();
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
