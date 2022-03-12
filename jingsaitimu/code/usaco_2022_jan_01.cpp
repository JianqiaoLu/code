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
#include <sstream> 
using namespace std;
vector<string> s1;
vector<string> s2;
vector<int> a1(26, 0);
vector<int> a2(26, 0);
pair<int, int> get()
{
    int k = 0, b = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s1[0].size(); j++)
        {
            if (s1[i][j] == s2[i][j])
            {
                k++;
            }
            else
            {
                a1[s1[i][j] - 'A'] ++;
                a2[s2[i][j] - 'A'] ++;
            }
        }
    }
    for (int i = 0; i < a1.size(); i++)
    {
        if (a1[i] and a2[i])  b += min(a1[i], a2[i]);
    }
    return make_pair(k, b);
}
int main()
{
    string s;
    for (int i = 0; i < 3; i++)
    {
        getline(cin, s);
        s1.push_back(s);
    }
    for (int i = 0; i < 3; i++)
    {
        getline(cin, s);
        s2.push_back(s);
    }
    std::fill(a1.begin(), a1.end(), 0);
    std::fill(a2.begin(), a2.end(), 0);
    auto ans = get();
    cout << ans.first << endl << ans.second << endl;
}
