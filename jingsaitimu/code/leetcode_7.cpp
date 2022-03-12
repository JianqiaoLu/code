#include "headl.h" 
class Solution {
public:
    int reverse(int x) {
        int r = 0, INT_MAX = 2e31 - 1, INT_MIN = -(2e31);
        while (x != 0)
        {
            if (r < INT_MIN / 10 || r > INT_MAX / 10) {
                return 0;
            }
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
