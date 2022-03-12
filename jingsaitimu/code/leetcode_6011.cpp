#include "headl.h" 
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size(), a2 = tires[0][0], mi = 0;
        vector<vector<int>> chosen(numLaps + 1, vector<int>(2));
        for (int i = 1; i <= numLaps; i++)
        {
            chosen[i][0] = tires[0][0] * (1 - pow(tires[0][1], numLaps - i + 1)) * 1.0 / (1 - tires[0][1]);
            chosen[i][1] = 0;
            for (int j = 1; j < n; j++)
            {
                int b = tires[j][0] * (1 - pow(tires[j][1], numLaps - i + 1)) * 1.0 / (1 - tires[j][1]);
                if (chosen[i][0] > b)
                {
                    chosen[i][0] = b;
                    chosen[i][1] = j;
                }
            }
        }
        int ans = tires[chosen[1][1]][0], pre = chosen[1][1], num = 1;
        for (int t = 2; t <= numLaps; t++)
        {
            int b = tires[pre][0] * pow(tires[pre][1], num) * (1 - pow(tires[pre][1], numLaps - t + 1)) * 1.0 / (1 - tires[pre][1]);
            if (b < chosen[t][0] + changeTime)
            {
                num++;
                ans += tires[pre][0] * pow(tires[pre][1], num - 1);
            }
            else
            {
                num = 1;
                pre = chosen[t][1];
                ans += tires[pre][0] * pow(tires[pre][1], num - 1) + changeTime;
            }
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<vector<int>> b = { {1,10},{2,2},{3,4} };
    Solution* a = new Solution();
    a->minimumFinishTime(b, 6, 5);
}
