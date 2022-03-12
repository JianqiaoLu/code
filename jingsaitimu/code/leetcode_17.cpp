#include "headl.h" 
class Solution {
public:
    vector<string> ntc = { {}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"},{"wxyz"} };
    string a;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        get(0, digits);
        return ans;
    }
    void get(int k, string digits)
    {
        if (k == digits.size())
        {
            ans.push_back(a);
            return;
        }
        int loc = digits[k] - '0' - 1;
        for (int i = 0; i < ntc[loc].size(); i++)
        {
            a.push_back(ntc[loc][i]);
            get(k + 1, digits);
            a.pop_back();
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->letterCombinations("23");
}
