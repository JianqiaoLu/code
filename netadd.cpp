#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
// int main()
// {
//  int a = 128;
//  for (int i = 7; i >=0;  -- i )
//  {
//  int  num = a & (1 << i);
//  cout<< a & (1<< i);
//  }
//
// }
//
int adds[1000][4];
int main()
{
  int m;
  printf("请输入有几个地址");

  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d %d %d", &adds[i][0], &adds[i][1], &adds[i][2], &adds[i][3]);
    printf("\n");
  }
  int num, locate = -1;
  int flag = 1;
  int j,k;
  for (j = 0; j < 4; j++)
  {
    num = j;
    for (k = 7; k >= 0; k--)
    {

      int temp = adds[0][j] & 1 << k;
      for (int i = 1; i < m; i++)
      {
        if (temp != (adds[i][j] & 1 << k)) 
        // 这里最重要的是搞清楚每次判度相同数字的时候应该是把m个数组都循环一便
        {
          locate = k;
          flag = 0;
          break;
        }
      }
      if (not flag)
      {
        break;
      }
    }
    if (not flag)
    {
      break;
    }
  }
  int cnt1 = 0, cnt2 = 0;
  for (int i = 7; i > locate; i--)
  {
    cnt1 += (adds[0][num] & 1 << i);
    cnt2 += 1 << i;
  }
  switch (num)
  {
  case 3:
    printf(" %d.%d.%d.%d \n 255.255.255.%d \n", adds[0][0], adds[0][1], adds[0][2], cnt1, cnt2);
    break;
  case 2:
    printf(" %d.%d.%d.0 \n 255.255.255.%d \n", adds[0][0], adds[0][1], cnt1, cnt2);
    break;
  case 1:
    printf(" %d.%d.0.0\n 255.255.255.%d \n", adds[0][0], cnt1, cnt2);
    break;
  case 0:
    printf(" %d.0.0.0\n 255.255.255.%d \n", cnt1, cnt2);
    break;
  default:
    break;
  }
}