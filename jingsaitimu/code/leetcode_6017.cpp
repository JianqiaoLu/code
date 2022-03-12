#include "headl.h" 
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = (long long)(1 + k) * k / 2;
        long long range = k;
        map<int, int> mm;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > range or mm.count(nums[i]))
            {
                continue;
            }
            else
            {
                range++;
                ans -= (long long)nums[i];
                ans += range;
            }
            mm[nums[i]] = 1;
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 53,41,90,33,84,26,50,32,63,47,66,43,29,88,71,28,83 };
    a->minimalKSum(b, 76);

}
