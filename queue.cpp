#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cctype>
#include <queue>
using namespace std;

queue<int> q, q2[100];

map<int, int> team;

int main()
{
  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    int n, x;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
      cin >> x;
      team[x] = i;
    }
  }
  cout << "请输入操作指令" << endl;
  string s;
  cin >> s;
  if (s[0] == 's')
  {
    return 0;
  }
  else if (s[0] == 'D')
  {
    int q1 = q.front();
    q2[q1].pop();
    if (q2[q1].empty())
    {
      q.pop();
    }
  }
  else
  {
    int x;
    cin >> x;
    int t = team[x];
    if (q2[t].empty())
    {
      q.push(t);
    }
    q2[t].push(x);
  }
}
