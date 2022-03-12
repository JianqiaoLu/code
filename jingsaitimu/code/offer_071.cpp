#include "headl.h" 
class Solution {
public:
    vector<int> a;
    Solution(vector<int>& w) {
        a = w;
    }

    int pickIndex() {
        int total = 0;
        for (int i = 0; i < a.size(); i++)
        {
            total += a[i];
        }
        int ab = rand() % total;
        int loc = 0;
        while (ab - a[loc] > 0)
        {
            ab -= a[loc];
            loc++;
        }
        return loc;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
