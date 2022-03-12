#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<iostream>  
#include<algorithm> 
#include<map> 
#include<vector> 
#include<cctype> 
#include<queue> 
#include<stack>
using namespace std;
vector<int> a(1e6, 0);
int get2(int target, int si)
{
    int l = 0, r = 0, k = a[l];
    int ans = 0;
    while (l < si)
    {
        while (k < target and r < si - 1)
        {
            r++;
            k += a[r];
        }
        if (k == target)
        {
            ans += r - l;
            r = r + 1;
            l = r;
            k = a[l];
        }
        else
        {
            ans = -1;
            break;
        }
    }
    return ans;
}
int get(int si)
{
    int sum = 0, m = -1, ans = si - 1;
    bool flag = false;
    for (auto i : a)
    {
        if (i) flag = true;
        sum += i;
        m = max(m, i);
    }
    if (not flag or (sum == m * si)) return 0;
    for (int i = m; i <= sum / 2 + 1; i++)
    {
        if (sum % i == 0)
        {
            int k = get2(i, si);
            if (k == -1) continue;
            else
            {
                ans = k;
                break;
            }
        }
    }
    return ans;;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int ans;
        std::fill(a.begin(), a.end(), 0);
        for (int j = 0; j < k; j++)
        {
            int c;
            cin >> c;
            a[j] = c;

        }
        int aa = get(k);
        cout << aa << endl;
    }

}
