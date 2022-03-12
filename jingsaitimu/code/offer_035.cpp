#include "headl.h" 
class Solution {
public:

    static bool compare1(const pair<double, string>* st1, const pair<double, string>* st2)
    {
        return st1->first > st2->first;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> dif;
        vector<pair<double, string>> ans;
        for (int i = 0; i < timePoints.size(); i++)
        {
            ans.push_back(make_pair(get(timePoints[i]), timePoints[i]));
        }
        sort(ans.begin(), ans.end(), compare1);
        for (int i = 1; i < ans.size(); i++)
        {
            int a = getdif(ans[i - 1].second, ans[i].second);
            dif.push_back(min(1440 - a, a));
        }
        int a = getdif(ans[0].second, ans[ans.size() - 1].second);
        dif.push_back(min(1440 - a, a));
        sort(dif.begin(), dif.end());
        return dif[0];
    }
    double get(string s)
    {
        int i = s.find(":");
        int hour = stoi(s.substr(0, i));
        int min = stoi(s.substr(i + 1));
        return  hour * 1.0 + 1.0 * min / 60;
    }
    int getdif(string s, string b)
    {
        int i = s.find(":");
        int hour = stoi(s.substr(0, i));
        int min = stoi(s.substr(i + 1));
        i = b.find(":");
        int hour1 = stoi(b.substr(0, i));
        int min1 = stoi(b.substr(i + 1));
        return (hour1 - hour) * 60 + (min1 - min);
    }

};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<string> b = { "12:12","12:13" };
    a->findMinDifference(b);
}
