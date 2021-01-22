#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cctype>
using namespace std;
struct building
{
  int id;
  int x, y, w, d, h;
  bool operator<(const building &b1)
      const
  {
    return x < b1.x || (x == b1.x && y < b1.y);
    // 这句话还挺叼的
  }
} builds[1000];

int cover(double loc, building b1)
{
  if (b1.x < loc && (b1.x + b1.w) > loc)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int vis(double loc, building b1)
{
  if (not cover(loc, b1))
  {
    return 0;
  }

  else
  {
    for (int i = 0; i < 1000; i++)
    {
      building b2 = builds[i];
      if (b2.y < b1.y && cover(loc, b2) && b2.h >= b1.h)
      {
        return 0;
      }
    }
    return 1;
  }
}

int main()
{
  int n;
  int x[n * 2];
  for (int i = 0; i < n; i++)
  {
    cin >> builds[i].x >> builds[i].y >> builds[i].w >> builds[i].d >> builds[i].h;
    x[i * 2] = builds[i].x;
    x[i * 2 + 1] = builds[i].x + builds[i].w;
  }
  sort(builds, builds + n);
  sort(x, x + 2 * n);
  for (int i = 0; i < n; i++)
  {
    int visalble = 0;
    double midloc = (double)x[i] + x[i + 1];
    for (int j = 0; j < 2 * n; j++)
    {
      if (vis(midloc, builds[j]))
      {
        visalble = 1;
        break;
      }
    }
    if (visalble)
    {
      cout << "可见" << endl;
    }
  }
}
