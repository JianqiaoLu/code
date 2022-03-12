
#include "headl.h" 


class Solution {
public:
    struct Comparator
    {
        bool operator()(const pair<float,int>& a, const pair<float,int> & b)
        {
            return a.second > b.second;
        }
    };
    struct tmp2 //重写仿函数
    {
        bool operator() (pair<float, int>a, pair<float, int>b)
        {
            return a.first > b.first; //大顶堆
        }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float, int>, vector<pair<float, int> >, Comparator> a;
        // priority_queue<pair<float, int> > a;
        vector<int> loc;
        vector<int> cloc;
        loc.push_back(0);
        bool flag;

        for (int i = 1; i < arr.size(); i++)
        {
            a.push(pair<float, int>((float)arr[0] / arr[i], i));
            loc.push_back(0);
        }
        pair<float, int> se;
        for (int i = 0; i < k - 1; i++)
        {
            flag = false;
            se = a.top();
            a.pop();
            if (loc[se.second] + 1 < se.second)
            {
                flag = true;
                loc[se.second] = loc[se.second] + 1;
                a.push(pair<float, int>((float)arr[loc[se.second]] / arr[se.second], se.second));
            }
        }
        se = a.top();
        return vector<int> {arr[loc[se.second]], arr[se.second]};


    }
};

int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    vector<int> aaa{ 1,2,3,5 };
    vector<int> ans1 = a->kthSmallestPrimeFraction(aaa, 3);
    int b = 1;

}