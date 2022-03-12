#include "headl.h" 
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> f(1 << (2 * numSlots));
        int n = 2 * numSlots, m = 0;
        for (int i = 0; i < f.size(); i++)
        {
            int c = __builtin_popcount(i);
            if (c >= nums.size()) continue;
            for (int j = 0; j < n; j++)

            {
                if ((i & (1 << j)) == 0)
                {
                    int  s = i | (1 << j);
                    f[s] = max(f[s], f[i] + (nums[c] & (j / 2 + 1)));
                    m = max(m, f[s]);
                }
            }
        }
        return m;
    }
};

class Solution {
public:
    int maximumANDSum(vector<int> &nums, int numSlots) {
        int ans = 0;
        vector<int> f(1 << (numSlots * 2));
        for (int i = 0; i < f.size(); ++i) {
            int c = __builtin_popcount(i);
            if (c >= nums.size()) continue;
            for (int j = 0; j < numSlots * 2; ++j) {
                if ((i & (1 << j)) == 0) { // 枚举空篮子 j
                    int s = i | (1 << j);
                    f[s] = max(f[s], f[i] + ((j / 2 + 1) & nums[c]));
                    ans = max(ans, f[s]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 1,2,3,4,5,6 };
    a->maximumANDSum(b, 3);

}
