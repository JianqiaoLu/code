#include "headl.h"
class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> graph;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        graph = graph;
        get(0,{});
        return ans;
    }
    void get(int togo, vector<int> path)
    {
        if (togo == graph.size() - 1)
        {
            path.push_back(togo);
            ans.push_back(path);
            return;
        }
        if (graph[togo].empty())
        {
            return;
        }
        else
        {
            path.push_back(togo);
            for (auto i : graph[togo])
                get(i, path);
        }
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution *a = new Solution();
    vector<vector<int>> b = {{{1,2},{3},{3},{}};
}
