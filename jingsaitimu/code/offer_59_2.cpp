#include "headl.h" 
class MaxQueue {
public:
    int l, r;
    vector<int> bique;
    queue <int> que;

    MaxQueue() {
        l = 0, r = 0;
    }

    int max_value() {
        if (l >= r) return -1;
        else return bique[l];
    }

    void push_back(int value) {
        if (l >= r)
        {
            bique.push_back(value);
            l = 0; r = 1;
        }
        bool flag = true;
        while (value > bique[r - 1])
        {
            r--;
            flag = false;

        }
        if (r == l)
        {
            bique = vector<int>{ 0 };
            bique[0] = value;
            l = 0; r = 1;
        }
        else if (not flag)
        {
            bique.push_back(value);
            r++;
        }
        else
        {
            bique[r] = value;
            r++;
        }
        que.push(value);
    }

    int pop_front() {
        if (l >= r)
        {
            return -1;
        }

        if (bique[l] == que.front())
        {
            l++;
            if (l == r)
            {
                l = 0, r = 0;
                bique = vector<int>();
            }
        
        int val = que.front();
        que.pop();
        return val;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
