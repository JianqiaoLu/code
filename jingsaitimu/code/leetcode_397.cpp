#include "headl.h" 


class  Solution {
public:
    int integerReplacement(int n) {
        int ans[n + 2];
        memset(ans,0,sizeof(ans));
        getans(n, ans);
        return ans[n ];
    }
    int getans(int n,int *ans){        

        if (n == 1)
        {
            return  ans[n];
        }
        else
        {
            if (n % 2)
            {
                if (!ans[n + 1])
                {
                    ans[n+1] = getans(n + 1,ans);
                }
                if (!ans[n - 1])
                {
                    ans[n-1] =getans(n - 1,ans);
                }
                ans[n] = 1 + min(ans[n + 1], ans[n - 1]);
                return ans[n];

            }
            else
            {
                if (!ans[n/2])
                {
                    ans[n/2] =  getans(n/2, ans); 
                }
                ans[n] = 1 + ans[n/2];
                return ans[n];
            }
        }

    }
  
};

int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    int ans1 = a->integerReplacement(7);
}