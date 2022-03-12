#include "headl.h" 
class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> ans = { 1,2,3,4,5 };
        int k = 5;
        int p2 = 2, p3 = 1, p5 = 1;
        while (k < n)
        {
            int a2 = ans[p2] * 2, a3 = ans[p3] * 3, a5 = ans[p5] * 5;
            int m = min(a2, min(a5, a3));
            k++;
            if (k == n)
            {
                return m;
            }
            ans.push_back(m);
            if (a2 == m) p2++;
            if (a3 == m) p3++;
            if (a5 == m) p5++;
        }
        return ans[n];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->nthUglyNumber(10);

}
