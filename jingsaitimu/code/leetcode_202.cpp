#include "headl.h" 
class Solution {
public:

    bool isHappy(int n) {
        map<int, int> a;
        while (true)
        {
            int nn = 0;
            while (n) {
                nn += (n % 10) * (n % 10);
                n /= 10;
            }
            if (nn == 1) return true;
            else if (a.count(nn)) return false;
            else
            {
                a[nn] = 1;
                n = nn;
            }
        }
        return false;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->isHappy(2);
}
