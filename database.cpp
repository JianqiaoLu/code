#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cctype>
using namespace std;
map<string, int> mpstr;
map<vector<int>, int> mpdup;
vector<string> vecstr;

int main()
{
  int n = 3, m =  3, a[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      string s;
      cin >> s;
      int index;
      if (!mpstr.count(s))
      {
        vecstr.push_back(s);
        index = vecstr.size() - 1;
        mpstr[s] = index;
      }
      else
      {
        index = mpstr[s];
      }
      a[i][j] = index;
    }
  }
  int flag = 0;
  int j;
  vector<int> ans;
  for (j = 0; j < m - 1; j++)
  {

    for (int i = 0; i < n; i++)
    {
      vector<int> vecint;
      vecint.push_back(a[i][j]);
      vecint.push_back(a[i][j + 1]);
      if (!mpdup.count(vecint))
      {
        mpdup[vecint] = i;
      }
      else
      {
        ans.push_back(i);
        ans.push_back(mpdup[vecint]);
        flag = 1;
        break;
      }

    }
    if (flag)
    {
      break;
    }
    
  }
  cout<<ans[0]<< j<< ans[1]<< j + 1<<endl;
}
