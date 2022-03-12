#include "headl.h" 
class Compare
{
public:
    bool operator() (vector<int> p1, vector<int> p2)
    {
        return p1[0] + p1[1] < p2[0] + p2[1];
    }
};
class Solution {
public:
    priority_queue<vector<int>, vector<vector<int>>, Compare> a;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        for (int i = 0; i < nums1.size(); i++)
        {
            int j;
            for (j = 0; j < nums2.size(); j++)
            {
                a.push({ nums1[i],nums2[j] });
                if (a.size() > k)
                {
                    a.pop();
                    break;
                }
            }
            if (j == 0) break;

        }
        vector<vector<int> > ans;
        while (not a.empty())
        {
            ans.push_back(a.top());
            a.pop();
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
