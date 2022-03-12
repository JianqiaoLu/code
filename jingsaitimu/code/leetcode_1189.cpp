#include "headl.h" 
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> a(26, 0);
        for (int i = 0; i < n; i++)
        {
            a[text[i] - 'a'] ++;
        }
        string b = "balon";
        int val = a['b' - 'a'];
        val = min(a['a' - 'a'], val);
        val = min(a['l' - 'a'] / 2, val);
        val = min(a['o' - 'a'] / 2, val);
        val = min(a['n' - 'a'] , val);
        return val;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
