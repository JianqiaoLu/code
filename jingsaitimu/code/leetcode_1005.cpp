#include "headl.h" 
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        for (int j = 0; j < k; j++)
        {
            int m = nums[0], loc = 0;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] < m)
                {
                    m = nums[i];
                    loc = i;
                }
            }
            nums[loc] = -nums[loc];
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }

};

int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> aaa{ 4,2,3 };
    int ans1 = a->largestSumAfterKNegations(aaa, 1);
    int b = 1;


}
