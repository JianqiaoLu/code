#include "headl.h" 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int f = 0, s = 0;
        int n1 = firstList.size(), n2 = secondList.size();
        vector<vector<int>> ans = {};
        while (f < n1 and s < n2)
        {
            if (firstList[f][0] <= secondList[s][0])
            {
                if (secondList[s][0] <= firstList[f][1])
                {
                    if (firstList[f][1] < secondList[s][1])
                    {
                        ans.push_back({ secondList[s][0],firstList[f][1] });
                        f++;
                    }
                    else
                    {
                        ans.push_back({ secondList[s][0],secondList[s][1] });
                        s++;
                    }


                }
                else f++;
            }
            else
            {
                if (firstList[f][0] <= secondList[s][1])
                {
                    if (firstList[f][1] < secondList[s][1])
                    {
                        ans.push_back({ firstList[f][0],firstList[f][1] });
                        f++;
                    }
                    else
                    {
                        ans.push_back({ firstList[f][0],secondList[s][1] });
                        s++;
                    }
                }
                else s++;
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
