#include "headl.h" 
class RecentCounter {
public:
    vector<int> ans;
    RecentCounter() {
    }
    int ping(int t) {
        ans.push_back(t);
        int l = max(0, t - 3000);
        int i;
        for (i = 0; i < ans.size(); i++)
        {
            if (ans[i] >= l)
            {
                break;
            }
        }
        return ans.size() - i;

    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
