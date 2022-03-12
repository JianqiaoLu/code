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
vector<int> a1(1e5 + 1);
vector<int> a2(1e5 + 1);
int get(int n)
{
    map<int, int> mm;
    for (int i = 0; i < n; i++)
    {
        mm[a2[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        a1[i] = mm[a1[i]];
    }
    int m = a1[0], k = 1;
    for (int i = 1; i < n; i++)
    {
        if (a1[i] > m)
        {
            m = a1[i];
            k++;
        }
    }
    return n - k;

}
int main()
{
    int n;
    cin >> n;
    std::fill(a1.begin(), a1.end(), 0);
    std::fill(a2.begin(), a2.end(), 0);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a1[i] = c;
    }
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a2[i] = c;
    }
    cout << get(n);
}

