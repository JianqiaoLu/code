#include "headl.h" 
class Solution {
public:
    int divide(int dividend, int divisor) {
        int a = -(dividend), b = -(divisor);
        bool flag = true;
        if ((dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0))  flag = false;
        int ans = 0;
        while (a <= b)
        {
            int c = 0;
            while (a < (b << (c + 1)))
            {
                c++;
            }
            a -= b << (c);
            if (flag)
            {
                if (ans + (1 << c) > (2e31 - 1)) return (2e31 - 1);
            }
            else
            {
                if (ans + (1 << c) > 2e31) return (-2e31);

            }

            ans += (1 << c);
        }
        if (not flag) ans = -ans;
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->divide(-2147483648, -1);

}
