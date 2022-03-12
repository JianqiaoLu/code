#include "headl.h" 
class Solution {
public:
    int divide(int a, int b) {
        if (a == -2147483648 and b == -1) return 2147483647;
        else if (a == -2147483648 and b == 1) return -2147483647;
        else if (a == 2147483647 and b == 1)  return 2147483647;
        else if (a == 2147483647 and b == -1)  return -2147483647;
        int cnt = 0;
        bool f = true;
        if (a > 0)
        {
            a = -a;
            f = not f;
        }
        if (b > 0)
        {
            b = -b;
            f = not f;
        }
        while (a <= 0)
        {
            int c = get(a, b);
            a += ((-b) << c);
            cnt += 1 << c;
        }
        cnt--;
        if (f) return cnt;
        else return -cnt;
    }
    int get(int a, int b)
    {
        int c = 0;
        while ((a >> (c + 1)) < b)
        {
            c++;
        }
        return c;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    // freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->divide(7, -3);

}
