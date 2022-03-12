#include "headl.h" 
class Solution {
public:
    vector<int> a;
    int minEatingSpeed(vector<int>& piles, int h) {
        a = piles;
        int l = 1, r = 0;
        for (auto i : piles) r = max(r, i);
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int gogo = get(m);
            if (gogo > h) l = m + 1;
            else if (gogo < h) r = m;
            else return m;
        }
        return l;
    }
    int get(int h)
    {
        int ab = 0;
        for (auto i : a)  ab += ceil(1.0 * i / h);
        return ab;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    vector<int> b = { 3,6,7,11 };
    Solution* ab = new Solution();
    ab->minEatingSpeed(b, 8);
}
