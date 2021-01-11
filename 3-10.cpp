#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct rect
{
  int w;
  int h;
};
bool sortrect(const rect &r1, const rect &r2)
{

  if (r1.w != r2.w)
    return r1.w > r2.w;
  else
    return r1.h > r2.h;
}
int main()
{
  rect rects[6];
  while (scanf("%d %d", &rects[0].w, &rects[0].h))
    ;
  {
    if (rects[0].w < rects[0].h)
    {
      swap(rects[0].w, rects[0].h);
    }
    for (int i = 1; i <= 5; i++)
    {
      scanf("%d %d", &rects[i].w, &rects[i].h);
      if (rects[i].w < rects[i].h)
      {
        swap(rects[i].w, rects[i].h);
      }
    }
    sort(rects, rects + 6, sortrect);
    if (rects[0].h != rects[1].h || rects[0].w != rects[1].w || rects[2].h != rects[3].h || rects[2].w != rects[3].w || rects[5].h != rects[4].h || rects[4].w != rects[5].w)
    {
      printf("impossible");
    }
    else if (rects[0].w != rects[2].w || rects[0].h != rects[4].w || rects[2].h != rects[4].h)
    {
      printf("impossible");
    }
    else
    {
      printf("yes");
    }
  }
}
