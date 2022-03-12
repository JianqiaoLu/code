#include "headl.h" 
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int i, val;
        i = 0;
        for (; i < k; i++)
        {
            val += (s[i] - 'a' + 1) * pow(power, i);
        }
        if (val % modulo == hashValue) return s.substr(i - k + 1, k);
        while (i < s.size())
        {
            val -= s[i - k] - 'a' + 1;
            val /= power;
            val += (s[i] - 'a' + 1) * pow(power, k - 1);
            if (val % modulo == hashValue)  return s.substr(i - k + 1, k);
            i++;
        }
        return "";
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    string ans = a->subStrHash("leetcode", 7, 20, 2, 0);
    int b = 1;


}
