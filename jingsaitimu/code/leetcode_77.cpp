#include "headl.h" 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return get(1, n, k, {});
    }
    vector<vector<int>> get(int num, int n, int k, vector<int> ans)
    {
        vector<vector<int>> aa;
        if (k == 1)
        {
            for (int i = num; i <= n; i++)
            {
                vector<int>  cop = ans;
                cop.push_back(i);
                aa.push_back(cop);
            }
        }
        else
        {
            for (int i = num; i <= n - (k - 1); i++)
            {
                vector<int>  cop = ans;
                cop.push_back(i);
                vector<vector<int>> bb = get(i + 1, n, k - 1, cop);
                for (int j = 0; j < bb.size(); j++)
                {
                    aa.push_back(bb[j]);
                }
            }
        }
        return aa;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->combine(4, 2);

}
