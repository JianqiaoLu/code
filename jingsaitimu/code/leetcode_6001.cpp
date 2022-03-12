#include "headl.h" 
class Solution {
public:
    struct greater
    {
        template<class T>
        bool operator()(T const& a, T const& b) const { return a > b; }
    };
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        vector<int> a;
        bool flag = true;
        if (num < 0) flag = false;
        num = abs(num);
        while (num != 0)
        {
            a.push_back(num % 10);
            num /= 10;
        }
        long long ans = 0;
        if (flag)
        {
            sort(a.begin(), a.end());
            int l = 0;
            while (a[l] == 0)
            {
                l++;
            }
            swap(a[l], a[0]);
            for (int i = 0; i < a.size(); i++)
            {
                ans += a[i] * pow(10, a.size() - i - 1);
            }
        }
        else
        {
            sort(a.begin(), a.end(), greater());
            for (int i = 0; i < a.size(); i++)
            {
                ans += a[i] * pow(10, a.size() - i - 1);
            }
            ans = 0 - ans;
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
int ans =     a->smallestNumber(-7605);
int b = 1;


}
