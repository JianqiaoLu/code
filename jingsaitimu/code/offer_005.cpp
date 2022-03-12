#include "headl.h" 
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            map<char, int > a;
            bool f = true;
            for (auto it : words[i]) a[it] = 1;
            for (int j = i + 1; j < n; j++)
            {
                for (auto it : words[j])
                {
                    if (a.count(it)) f = false;
                }
                int kkk = words[i].size() * words[j].size();
                if (f)  ans = max(ans, kkk);
            }
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
