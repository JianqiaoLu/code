#include "headl.h" 
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans = 0, t = 0;
        long long l = 0;
        long long r = (long long)totalTrips * (long long)time[0];
        while (l < r)
        {
            long long  m = l + (r - l) / 2;
            long long a = 0;
            for (int i = 0; i < time.size(); i++)
            {
                a += m / time[i];
            }
            if (a >= totalTrips)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
