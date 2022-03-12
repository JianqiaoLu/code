#include "headl.h" 

class Solution {
public:
    struct greater
    {
        template<class T>
        bool operator()(T const& a, T const& b) const { return a > b; }
    };
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> a, b;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater());
        int l1 = 0, l2 = 0, r1 = a.size(), r2 = b.size();
        vector<int> ans;
        while (l1 < r1 or l2 < r2)
        {
            ans.push_back(a[l1]);
            l1++;
            if (l2 < r2) ans.push_back(b[l2]);
            l2++;
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
