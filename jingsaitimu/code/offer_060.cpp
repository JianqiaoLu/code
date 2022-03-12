#include "headl.h" 
class Compare
{
public:
    bool operator() (pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first < p2.first;
    }
};
class Solution {
public:
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> a;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0, r = 0;
        while (l < nums.size())
        {
            while(nums[r] == nums[l] and r < nums.size()) 
            { 
                r ++;
            }
            a.push(make_pair(nums[l], r - l));
            if (a.size() > k)
            {
                a.pop();
            }
            l = r;
        }
        vector<int> ans;
        while (not a.empty())
        {
            ans.push_back(a.top().first);
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
    vector<int> b ={1};
    a->topKFrequent(b,1);

}
