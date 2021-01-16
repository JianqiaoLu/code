#include <stdio.h>
#include <math.h>
#include <string.h>
struct locate
{
  int x;
  int y;
};
int valid(locate l1)
{
  if (l1.x <= 8 && l1.x >= 1 && l1.y <= 8 && l1.y >= 1)
  {
    return 1;
  }
  return 0;
}
int qipan[10][10];
int neigh(locate l1, locate *vnei)
{
  int num = 0;
  for (int x = -1; x < 2; x++)
  {
    for (int y = 0; y < 2; y++)
    {
      if (x == 0 && y == 0)
      {
        continue;
      }
      else
      {
        int newx = l1.x + x;
        int newy = l1.y + y;
        locate l2;
        l2.x = newx, l2.y = newy;
        if (qipan[newx][newy] != 0 && valid(l2))
        {
          vnei[++num] = l2;
        }
      }
    }
  }
  return num;
}

void xiaqi(locate l1)
{
  locate vnei[9];
  int num = neigh(l1, vnei);
  int sign = qipan[l1.x][l1.y];
  for (int i = 1; i <= num; i++)
  {
    locate l2 = vnei[i];
    int sign1 = qipan[l2.x][l2.y];
    while (sign1 == -sign)
    {
      qipan[l2.x][l2.y] = -qipan[l2.x][l2.y];
      l2.x = l2.x + l2.x - l1.x;
      l2.y = l2.y + l2.y - l1.y;
      sign1 = qipan[l2.x][l2.y];
    }
  }
}

int main()
{
  memset(qipan, 1, sizeof(qipan));
  int x, y, hei;
  printf("输入棋子位置, 1 表示黑子，-1表示白j");
  while (scanf("%d %d %d", &x, &y, &hei) == 2 && x != -1)
  {
    qipan[x][y] = hei;
  }
  int heibai = 1;
  locate l2;
  while (true)
  {
    int ansnum;
    locate ans[100];
    ansnum = display(heibai, ans);
    if (not ansnum)
    {
      continue;
      heibai++;
    }

    for (int i = 1; i < ansnum; i++)
    {
      printf("可下的地方(%d,%d) \n", ans[i].x, ans[i].y);
    }

    if (heibai % 2 == 1)
    {
      printf("当前黑子落位");
    }
    else
    {
      printf("当前白子落位");
    }
    printf("请输入要下的地方");
    scanf("%d%d", &l2.x, &l2.y);
    xiaqi(l2);
    heibai++;
  }
}

int display(int heibai, locate *ans)
{
  int ansnum = 0;
  for (int i = 1; i < 9; i++)
  {
    for (int j = 1; j < 9; j++)
    {
      if (qipan[i][j] != 0)
      {
        locate vnei[9];
        locate l1;
        l1.x = i, l1.y = j;
        int num = neigh(l1, vnei);
        if (not num)
        {
          int sign;
          sign = qipan[l1.x][l1.y];
          if (heibai % 2 == 1)
          {
            if (sign == -1)
            {
              continue;
            }
          }
          else
          {
            if (sign == 1)
            {
              continue;
            }
          }

          for (int iter = 1; iter <= num; iter++)
          {
            locate l2 = vnei[iter];
            int sign1, sign2;
            sign1 = qipan[l2.x][l2.y];
            if (sign1 == sign)
            {
              continue;
            }
            locate l3 = l2;
            do
            {
              l3.x = l3.x + l2.x - l1.x;
              l3.y = l3.y + l2.y - l1.y;
              int sign2 = qipan[l3.x][l3.y];
            } while (valid(l3) && not sign2 && sign2 != sign);
            if (sign2 == 0)
            {
              ans[++ansnum] = l3;
            }
          }
        }
      }
    }
  }
  return ansnum;
}
