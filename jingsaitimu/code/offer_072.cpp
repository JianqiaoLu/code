#include "headl.h" 
class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = 2e31;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (m * m > x) r = m - 1;
            else if (m * m < x) l = m;
            else return m;
        }
        return l;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
