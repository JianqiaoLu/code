#include "headl.h" 
class Solution {
public:
    static bool compare(const vector<int>& odd1, const vector<int>& odd2)
    {
        return (odd1[1] != odd2[1]) ? (odd1[1] < odd2[1]) : (odd1[0] < odd2[1]);

    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<vector<int>> go;
        map<int, int> mm;
        for (int i = 0; i < arr2.size(); i++)
        {
            mm[arr2[i]] = i;
        }
        for (int i = 0; i < arr1.size(); i++)
        {
            int v = arr1[i];
            go.push_back({ v,(mm.count(v)) ? mm[v] : 1001 });
        }
        sort(go.begin(), go.end(), compare);
        vector<int > ans;
        for (int i = 0; i < go.size(); i++)
        {
            ans.push_back(go[i][0]);
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
