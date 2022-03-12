#include "headl.h" 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> a;
        vector<int> ans;
        int n = asteroids.size();
        a.push(asteroids[0]);
        for (int i = 1; i < n; i++)
        {
            int c = asteroids[i];
            bool flag = false;
            while (not a.empty())
            {
                int b = a.top();
                if ((b > 0 and c < 0))
                {
                    a.pop();
                    if (abs(b) > abs(c)) c = b;
                    else if (abs(b) == abs(c))
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (not flag) a.push(c);
        }
        while (not a.empty())
        {
            ans.push_back(a.top());
            a.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();

}
