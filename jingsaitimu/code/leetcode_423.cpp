#include "headl.h" 



class Solution {
public:
    // string* tonum = ;
    vector<string> tonum = { "zero", "one", "two","three","four","five","six","seven","eight","nine" };
    int* redt(int* dt, int iter) {
        string s = tonum[iter];
        for (int i = 0; i < s.size(); i++)
        {
            dt[s[i] - 'a'] --;
        }
        return dt;
    }
    vector<int>  dp(int* dtn, vector<int> ans, int iter)
    {
        if (dtn == 0)
        {
            return ans;
        }
        dp(dtn, ans, iter - 1);
        int* dt = redt(dtn, iter);
        ans.push_back(iter);
        dp(dt, ans, iter - 1);
    }

    vector<int> originalDigits(string s) {

        int dt[26] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            dt[s[i] - 'a'] ++;
        }
        vector<int> ans = dp(dt, vector<int> {}, 9);
        return ans;
    }


};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> ans1 = a->originalDigits("owoztneoer");
    int aaa = 1;
}
