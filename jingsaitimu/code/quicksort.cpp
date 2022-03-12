#include "headl.h" 
class Solution
{
public:
    void quicksort(vector<int>& a, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        else
        {
            int p = get(a, l, r);
            quicksort(a, l, p - 1);
            quicksort(a, p + 1, r);
        }
    }
    int get(vector<int>& a, int l, int r)
    {
        int p = r;
        while (l < r)
        {
            while (a[l] < a[p] and l < r)l++;
            while (a[r] >= a[p] and r > l)r--;
            swap(a[l], a[r]);
        }
        swap(a[l], a[p]);
        return l;
    }

}
;
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 3,2,4,5,1 };
    a->quicksort(b, 0, b.size() - 1);
    int c = 1;
}
