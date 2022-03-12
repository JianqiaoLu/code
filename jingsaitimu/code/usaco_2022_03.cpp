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
bool get(vector<string> b, string s, int k1, vector<int>& vis, int r)
{
    bool a = false;
    if (r == 0) return true;
    else if (k1 == 4) return false;
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (vis[i]) continue;
            if (b[k1].find(s[i]) != string::npos)
            {
                vis[i] = 1;
                a = a or get(b, s, k1 + 1, vis, r - 1);
                vis[i] = 0;
            }
        }
        a = a or get(b, s, k1 + 1, vis, r);
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> b;
    for (int i = 0; i < 4; i++)
    {
        string a;
        cin >> a;
        b.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        vector<int> vis(c.size(), 0);
        bool ans = get(b, c, 0, vis, c.size());
        cout << ans <<endl;;
    }
}
