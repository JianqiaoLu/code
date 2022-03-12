#include "headl.h" 
vector<long long> a(1e5 + 1, 0);
int get(int n)
{
    long long mi = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < mi) mi = a[i];
    }
    long long ans;
    vector<long long> b(n, 0);
    bool flag = true;
    for (ans = mi; ans >= 0; ans--)
    {
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i] - ans;
        }
        for (int i = 1; i < n - 1; i++)
        {
            if ((b[i] >= b[i - 1] and b[i] >= b[i + 1]) and b[i] != (b[i - 1] + b[i + 1]))
            {
                flag = false;
                break;
            }
        }
        if (flag)return ans;
    }
    return -1;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        std::fill(a.begin(), a.end(), 0);
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            a[i] = m;
        }
        cout << get(n) << endl;
    }
}
