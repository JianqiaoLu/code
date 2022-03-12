#include "headl.h" 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>  a;
        a.push(make_pair(0, temperatures[0]));
        vector<int> ans(temperatures.size());
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (not a.empty())
            {
                while (not a.empty())
                {
                    auto b = a.top();
                    if (b.second < temperatures[i])
                    {
                        a.pop();
                        ans[b.first] = i - b.first;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            a.push(make_pair(i, temperatures[i]));
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
