#include "headl.h" 
class Solution {
public:
    vector<double> dicesProbability(int n) {
        int factor = pow(6, n);
        vector<vector<double>> ans(2, vector<double>(7));
        for (int i = 1; i < 7; i++) ans[1][i] = 1;
        int k = 1;
        vector<double> a;
        while (k < n)
        {
            k++;
            a = vector<double>(k * 6 + 1, 0);
            for (int i = k; i < k * 6 + 1; i++)
            {
                int z = 1;
                while (z <= 6 )
                {
                    if((i - z) > 0 and (i - z) <= (k - 1) * 6) a[i] += ans[k - 1][i - z];
                    z++;
                }
            }
            ans.push_back(a);
            if (k == n) break;
        }
        vector<double> b;
        for (int i = k; i < k * 6 + 1; i++)
        {
            b.push_back(ans[k][i] / factor);
        }
        return b;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    auto b = a->dicesProbability(2);
    int c = 1;

}
