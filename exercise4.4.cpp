#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

#include <algorithm>

using namespace std;

struct aa
{
  char a1;
  char a2;
};

bool sortval(aa x, aa y)
{
  if (x.a1 != y.a1)
  {
    return x.a1 > y.a1;
  }
  else
  {
    return x.a2 > y.a2;
  }
}

int main()
{
  aa ans1[3], ans2[3];
  char cuba1[6], cuba2[6];
  while (scanf("%s %s", cuba1, cuba2))
  {
    for (int i = 0; i < 3; i++)
    {
      ans1[i].a1 = cuba1[i] > cuba1[5 - 1] ? cuba1[i] : cuba1[5 - 1];
      ans1[i].a2 = cuba1[i] <= cuba1[5 - 1] ? cuba1[i] : cuba1[5 - 1];
      ans2[i].a1 = cuba2[i] > cuba2[5 - 1] ? cuba2[i] : cuba2[5 - 1];
      ans2[i].a2 = cuba2[i] <= cuba2[5 - 1] ? cuba2[i] : cuba2[5 - 1];
    }
    sort(ans1, ans1 + 3, sortval);
    sort(ans2, ans2 + 3, sortval);
    int flag = 1;
    for (int i = 0; i < 3; i++)
    {
      if (ans1[i].a1 != ans2[i].a1)
      {
        flag = 0;
        break;
      }
    }
    if (flag)
    {
      printf("yes");
    }
    else
    {
      printf("no");
    }
  }
}