
#include "headl.h" 
class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> ans;
    int sum, se;
    MovingAverage(int size) {
        sum = 0;
        se = size;
    }

    double next(int val) {
        ans.push(val);
        sum += val;
        int n = ans.size();
        if (n > se)
        {
            sum -= ans.front();
            ans.pop();
            n--;
        }
        return 1.0 * sum / n;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
