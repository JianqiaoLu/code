#include "headl.h" 
class Solution {
public:
    vector<vector<int>> change = { {0,1},{1,0}, {-1, 0}, {0,-1} };
    bool valid(vector<int> a, int n)
    {
        return ((a[0] < n) and (a[0] >= 0) and (a[1] < n) and (a[1] >= 0));
    }
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n, vector<int>(n, 1));
        vector<vector<int>> note(n, vector<int>(n, 0));
        vector<int> pos = { 0, 0 };
        note[pos[0]][pos[1]] = 1;
        bool flag = true;
        int cho = 0;
        while (flag)
        {
            flag = false;
            int i = 0;
            while (i < 4)
            {

                vector<int> a = { pos[0] + change[cho][0], pos[1] + change[cho][1] };
                if (valid(a, n) and !note[a[0]][a[1]])
                {
                    flag = true;
                    note[a[0]][a[1]] = 1;
                    ans[a[0]][a[1]] = ans[pos[0]][pos[1]] + 1;
                    pos = a;
                    break;
                }
                i++;
                cho = (cho + 1) % 4;
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
