#include "headl.h" 
class Solution1 {
public:
    void quicksort(vector<string>& ans, int l, int h)
    {
        if (l >= h) return;
        int i = l, j = h;
        while (i < j)
        {
            while ((ans[i] + ans[h] < ans[h] + ans[i]) and i < j) i++;
            while ((ans[j] + ans[h] > ans[h] + ans[j]) and i < j) j--;
            swap(ans[i], ans[j]);
        }
        swap(ans[h], ans[i]);
        quicksort(ans, l, i - 1);
        quicksort(ans, i + 1, h);
    }
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(to_string(nums[i]));
        }
        quicksort(ans, 0, n - 1);
        string c = "";
        for(auto item : ans) c += item;
        return c;
    }
};
class Solution {
public:
    static bool compare(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) return a.first < b.first;
        else return a.second.size() > b.second.size();
    }
    string minNumber(vector<int>& nums) {
        vector<pair<int, string>> a;
        int n = nums.size();
        int maxd = 0;
        for (int i = 0; i < n; i++)
        {
            int b = nums[i];
            int dig = 0;
            string c = "";
            while (b != 0)
            {
                c.push_back(b % 10 + '0');
                b = b / 10;
            }
            reverse(c.begin(), c.end());
            int t = c.size();
            maxd = max(maxd, t);
            a.push_back(make_pair(nums[i], c));
        }
        for (int i = 0; i < n; i++)
        {
            a[i].first = a[i].first * pow(10, maxd - a[i].second.size());
        }
        sort(a.begin(), a.end(), compare);
        string ans;
        for (int i = 0; i < a.size(); i++)
        {
            ans += (a[i].second);
        }
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> b = { 3,30,34,5,9 };
    a->minNumber(b);

}
