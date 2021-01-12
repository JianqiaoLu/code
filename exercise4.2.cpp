#include <stdio.h>
#include <math.h>
#include <string.h>
int n = 5;
struct locate
{
  int x;
  int y;
};

int insquare(locate l1)
{
  if (l1.x < n && l1.x > 0 && l1.y < n && l1.y > 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int squares[10][10];

int main()
{
  memset(squares, 0, sizeof(squares));
  int x, y;
  printf("请输入有黑点的坐标，输入0表示输入完成 \n ");
  int ans[n];
  memset(ans, 0, sizeof(ans));
  while (scanf("%d", &x, &y) == 2 && x != -1)
  {
    squares[x][y] = 1;
  }
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      for (int k = j; k < n; k++)
      {
        locate l1;
        l1.y = i;
        l1.x = j;
        locate l2;
        l2.y = i;
        l2.x = k;
        if (connect(l1, l2))
        {
          locate l3, l4;
          l3.x = l2.x;
          l3.y = l2.y + (k - j);
          l4.x = l1.x;
          l4.y = l3.y;
          if (insquare(l3) && insquare(l4) && connect(l2, l3) && connect(l3, l4) && connect(l4, l1))
          {
            ans[k - j]++;
          }
        }
      }
    }
  }
}
