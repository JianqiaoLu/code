#include "headl.h" 
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (gcd(i, j) == 1)
                {
                    string b = to_string(j);
                    b.push_back('/');
                    b += to_string(i);
                    ans.push_back(b);
                }
            }
        }
        return ans;

    }
    int gcd(int a, int b)
    {
        if (a < b) swap(a, b);
        while (b != 1 and a != b)
        {
            int c = a - b;
            a = b;
            b = c;
            if (a < b) swap(a, b);
        }
        return b;
    }

};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->simplifiedFractions(4);

}
