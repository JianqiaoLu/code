#include "headl.h" 

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> dic(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            dic[s[i] - 'a'] ++;
        }

        string ans;
        int k = 0, repeat = 1;
        for (int i = 0; i < s.size(); i++)
        {
            bool flag = false;
            for (int j = 25; j >= 0; j--)
            {
                if (not dic[j]) continue;
                if (ans.empty())
                {
                    ans.push_back(j + 'a');
                    dic[j] --;
                    k++;
                    repeat = 1;
                    flag = true;
                    break;
                }
                else
                {
                    if ((j + 'a') == ans[k - 1] and repeat < repeatLimit)
                    {
                        repeat++;
                        dic[j] --;
                        ans.push_back(j + 'a');
                        k++;
                        flag = true;
                        break;
                    }
                    else if ((j + 'a') != ans[k - 1])
                    {
                        repeat = 1;
                        dic[j] --;
                        ans.push_back(j + 'a');
                        k++;
                        flag = true;
                        break;
                    }
                }


            }
            if (not flag) break;
        }
        return ans;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    a->repeatLimitedString("bplpcfifosybmjxphbxdltxtfrjspgixoxzbpwrtkopepjxfooazjyosengdlvyfchqhqxznnhuuxhtbrojyhxwlsrklsryvmufoibgfyxgjw", 1);

}
