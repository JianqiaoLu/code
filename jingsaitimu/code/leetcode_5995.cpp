#include "headl.h" 
class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        vector<vector<string>> ans = { {words[0]} };
        for (int i = 1; i < words.size(); i++)
        {
            bool pushed = false;
            for (int j = 0; j < ans.size(); j++)
            {
                if(pushed) break;
                for (int z = 0; z < ans[j].size(); z++)
                {
                    string a, b;
                    bool flag = true;
                    if (ans[j][z].size() < words[i].size())
                    {
                        a = ans[j][z];
                        b = words[i];
                    }
                    else
                    {
                        a = words[i];
                        b = ans[j][z];
                    }
                    if ((b.size() - a.size()) == 1)
                    {
                        int l = 0, r = 0, co = 0;
                        while (r < a.size())
                        {
                            if (a[r] == b[l])
                            {
                                r++;
                                l++;
                            }
                            else
                            {
                                if (co)
                                {
                                    flag = false;
                                    break;
                                }
                                else
                                {
                                    co++;
                                    l++;
                                }
                            }
                        }
                    }
                    else if ((b.size() - a.size()) == 0)
                    {
                        int l = 0, r = 0, co = 0;
                        while (r < a.size())
                        {
                            if (a[r] == b[l])
                            {
                                r++;
                                l++;
                            }
                            else
                            {
                                if (co)
                                {
                                    flag = false;
                                    break;
                                }
                                else
                                {
                                    co++;
                                    l++;
                                    r++;
                                }
                            }
                        }
                    }
                    else  flag = false;
                    if (flag)
                    {
                        ans[j].push_back(words[i]);
                        pushed = true;
                        break;
                    }
                }
            }
            if(not pushed) ans.push_back({words[i]});
        }
        int m = 0;
        int n = ans.size();
        for (int i = 0; i < n;i++)
        {
            if (m < ans[i].size())  m = ans[i].size();
        }
        return { n, m };
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<string> b = {"a","ab","abc"};
    Solution* a = new Solution();
    a->groupStrings(b);

}
