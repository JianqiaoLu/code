#include "headl.h" 
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        long long sum = beans[0], sum2 = 0;
        vector<long long> a(n, 0), b(n, 0);
        for (int i = 1; i < n; i++)
        {
            a[i] = sum;
            sum += beans[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            long long c = (long long) (n - 1 - i) * (beans[i + 1] - beans[i]);
            b[i] = b[i + 1] + c;
        }
        long long ans = a[0] + b[0];
        for (int i = 1; i < n; i++)
        {
            if ((a[i] + b[i]) < ans) ans = (a[i] + b[i]);
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
