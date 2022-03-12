#include "headl.h" 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> a(n, 0), b(n, 0);
        b[n - 1] = n - 1;
        for (int i = 1; i < n; i++)
        {
            int l;
            if (heights[i] = heights[i - 1])  a[i] = a[i - 1];
            else
            {

                if (heights[i] < heights[i - 1])
                    l = a[i - 1];
                else
                    l = i;
                while (l >= 0 and heights[l] >= heights[i])
                    l--;
                if (l < 0)
                    a[i] = 0;
                else a[i] = l + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            int r;
            if (heights[i] = heights[i + 1]) b[i] = b[i + 1];
            else
            {
                if (heights[i] < heights[i + 1]) r = b[i + 1];
                else r = i;
                while (r < n and heights[r] >= heights[i]) r++;
                if (r = n) b[i] = n - 1;
                else b[i] = r - 1;
            }

        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] *  (b[i] - a[i]  + 1));
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 2,1,5,6,2,3 };
    a->largestRectangleArea(b);


}
