#include "headl.h" 
class Solution {
public:
    int m = 0;
    vector<int> vis;
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vis = vector<int>(numSlots + 1, 0);
        get(nums, numSlots, 0, 0);
        return m;
    }
    void get(vector<int>& nums, int slots, int k, int v)
    {
        if (k == nums.size())
        {
            m = max(m, v);
            return;
        }
        for (int i = 1; i <= slots; i++)
        {
            if (vis[i] < 2)
            {
                vis[i] ++;
                get(nums, slots, k + 1, v + (i & nums[k]));
                vis[i] --;
            }
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 1,3,10,4,7,1 };
    a->maximumANDSum(b, 9);

}
