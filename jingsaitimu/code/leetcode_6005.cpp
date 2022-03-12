#include "headl.h" 
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), fm1 = 0, sm1 = 0, fm2 = 0, sm2 = 0;
        int fm1_v = -1, fm2_v = -1;
        map<int, int> a, b;
        for (int i = 0; i < n; i++)
        {
            if ((i+1) % 2 != 0)
            {
                if (a.count(nums[i])) a[nums[i]] ++;
                else a[nums[i]] = 1;
                if (a[nums[i]] > fm1)
                {
                    fm1 = a[nums[i]];
                    fm1_v = nums[i];
                }
                else if (a[nums[i]] > sm1) sm1 = a[nums[i]];
            }
            else
            {
                if (b.count(nums[i])) b[nums[i]] ++;
                else b[nums[i]] = 1;
                if (b[nums[i]] > fm2)
                {
                    fm2 = b[nums[i]];
                    fm2_v = nums[i];
                }
                else if (b[nums[i]] > sm2) sm2 = b[nums[i]];
            }
        }
        if (fm1_v != fm2_v)
        {
            return ((n + 1) / 2 - fm1) + (n / 2 - fm2);
        }
        else
        {
            return min(((n + 1) / 2 - fm1 + (n / 2 - sm2)), ((n + 1) / 2 - sm1 + (n / 2 - fm2)));
        }

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b ={3,1,3,2,4,3};
    a->minimumOperations(b);

}
