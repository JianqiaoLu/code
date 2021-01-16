#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> pile[100];
int n;
void find_block(int a, int &p, int &h)
{
  for (p = 0; p < n; p++)
  {
    for (h = 0; h < pile[p].size(); h++)
    {
      if (pile[p][h] == a)
      {
        return;
      }
    }
  }
}
void moveonto(int &p1, int &h1, int &p2, int &h2)
{
  for (int i = h2 + 1; i < pile[p2].size(); i++)
  {
    int b = pile[p2][i];
    pile[b].push_back(b);
  }
  pile[p2].resize(h2 + 1);
  for (int i = h1 + 1; i < pile[p1].size(); i++)
  {
    int b = pile[p1][i];
    pile[b].push_back(b);
  }
  pile[p2].push_back(pile[p1][h1]);
  pile[p1].resize(h1);
  return;
}

void moveover(int &p1, int &h1, int &p2)
{
  for (int i = h1 + 1; i < pile[p1].size(); i++)
  {
    int b = pile[p1][i];
    pile[b].push_back(b);
  }
  pile[p2].push_back(pile[p1][h1]);
  pile[p1].resize(h1);
  return;
}

void pileonto(int &p1, int &h1, int &p2, int &h2)
{
  for (int i = h2 + 1; i < pile[p2].size(); i++)
  {
    int b = pile[p2][i];
    pile[b].push_back(b);
  }
  pile[p2].resize(h2 + 1);
  for (int i = h1; i < pile[p1].size(); i++)
  {
    int b = pile[p1][i];
    pile[p2].push_back(b);
  }

  pile[p1].resize(h1);
}

void pileover(int &p1, int &h1, int &p2)
{
  for (int i = h1; i < pile[p1].size(); i++)
  {
    int b = pile[p1][i];
    pile[p2].push_back(b);
  }
  pile[p1].resize(h1);
}

int main()
{
  int a, b;
  string s1, s2;
  while (cin >> s1 >> a >> s2 >> b)
  {
    int p1, h1, p2, h2;

    find_block(a, p1, h1);
    find_block(b, p2, h2);
    if (s1 == "move")
    {
      if (s2 == "over")
      {
        /* code */
      }
      else
      {
        /* code */
      }
    }
    else
    {
      if (s2 == "over")
      {
        /* code */
      }
      else
      {
        /* code */
      }
    }
  }
}
