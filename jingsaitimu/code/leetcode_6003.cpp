#include "headl.h" 
class Solution {
public:
    int minimumTime(string s) {
        int a = 1;
        return get(s, 0, s.size() - 1);
    }
    int get(string s, int l, int r)
    {
        if (l > r) return 0;
        int sl = l, sr = r;
        int ans = 0;
        while (sl <= sr)
        {
            if (s[sl] == '0') sl++;
            else
            {
                if (sl != l + 1)
                {
                    int ans1 = (sl - l + 1 + get(s, sl + 1, r));
                    s[sl] = '0';
                    int ans2 = (2 + get(s, l, r));
                    s[sl] = '1';
                    ans = min(ans1, ans2);
                    break;
                }
                else ans = (sl - l + 1 + get(s, sl + 1, r));
            }

            if (s[sr] == '0') sr--;
            else
            {
                if (sr != r - 1)
                {
                    int ans1 = (r - sr + 1 + get(s, l, sr - 1));
                    s[sr] = '0';
                    int ans2 = (2 + get(s, l, r));
                    s[sr] = '1';
                    ans = min(ans1, ans2);
                    break;
                }
                else
                {
                    ans = (r - sr + 1 + get(s, l, sr - 1));
                }

            }
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    Solution* a = new Solution();
    a->minimumTime("1001010101");

}
