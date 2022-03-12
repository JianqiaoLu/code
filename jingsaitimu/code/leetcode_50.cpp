#include "headl.h" 
// class Solution {
// public:
//     double myPow(double x, int n) {
//         bool flag = true;
//         if (n < 0) flag = false;
//         double ans = 1;
//         n = abs(n);
//         while (n > 0)
//         {
//             int k = 0;
//             double v = x;
//             while ((1 << (k + 1) < INT_MAX) and n > 1 << (k + 1))
//             {
//                 v *= v;
//                 k++;
//             }
//             n -= 1 << (k);
//             ans *= v;
//         }
//         if (flag)
//         {
//             return ans;
//         }
//         else return 1.0 / ans;

//     }
// };
void get(int d)
{
    while (d > 0)
    {
        cout << d % 2 << " ";
        d = d / 2;
    }

}
int main()
{
    freopen("test_in.txt", "r", stdin);
    get(8);

}
