#include "headl.h" 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, n = arr.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int ml = ((m - 1) >= 0) ? arr[m - 1] : -1;
            int mr = ((m + 1) <= n) ? arr[m + 1] : -1;
            if (arr[m] > ml and arr[m] > mr) return m;
            else if (arr[m] > ml and arr[m] < mr) l = m + 1;
            else if (arr[m] < ml and arr[m] > mr) r = m - 1;
        }
        return r;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
