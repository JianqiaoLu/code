#include "headl.h" 
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 1; i < words.size(); i++)
        {
            int l = 0, r = 0, s1 = words[i - 1].size(), s2 = words[i].size();
            while (l < s1 and r < s2)
            {
                if (words[i - 1][l] != words[i][r])
                {
                    if (order.find(words[i - 1][l]) > order.find(words[i][r])) return false;
                    else  break;
                }
                l++;
                r++;
            }
            if (r == s2 and s2 < s1)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
