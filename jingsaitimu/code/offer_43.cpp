#include "headl.h" 
class Solution {
public:
    int countDigitOne(int n) {
        int d = 0, n1 = n;
        vector<int> b;
        while (n1 != 0)
        {
            b.push_back(n1 % 10);
            n1 /= 10;
            d++;
        }
        vector<int> ans(d , 0);
        ans[1] = 1;
        for (int i = 2; i < d ; i++)
        {
            ans[i] = pow(10, i - 1) + 9 * ans[i - 1];
        }
        int c = 0;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            if (b[i] > 1)
            {
                c += pow(10, i);
                c += (b[i] - 2) * ans[i];
            }
        }
        return c + ans[ans.size() - 1];
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->countDigitOne(12);

}
