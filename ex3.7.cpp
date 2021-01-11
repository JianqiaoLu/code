#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
#include <iostream>
int comp(char *s1, char *s2)
{
  int len = strlen(s1);
  for (int i = 0; i < len; i++)
  {
    if (s1[i] > s2[i])
      return 0;
  }
  return 1;
}
int main()
{
  int m, n;
  while (scanf("%d %d", &m, &n))
  {
    if (m < 4 || m > 50 || n < 4 || n > 1000)
      continue;
    char s[100][100];
    // 原来一个字符串数组要用二维数组来输入啊
    for (int i = 0; i < m; i++)
    {
      scanf("%s", s[i]);
    }
    int ans[100];
    memset(ans, 0, sizeof(int) * m);
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < m; k++)
      {
        if (k == j)
          continue;
        for (int z = 0; z < n; z++)
        {
          if (s[j][z] != s[k][z])
          {
            ans[j]++;
          }
        }
      }
    }
    int max = ans[0];
    int index = 0;
    for (int i = 1; i < m; i++)
    {
      if (max <= ans[i])
      {
        index = i;
        max = ans[i];
      }
    }

    int indexs[100];
    int in = 0;
    for (int i = 0; i < m; i++)
    {
      if (max == ans[i])
      {
        indexs[in++] = i;
      }
    }
    if (in == 0)
      printf("%s", s[index]);
    else
    {
      int index1 = 0;
      for (int i = 1; i < in; i++)
      {
        if (not comp(s[index1], s[i]))
          index1 = i;
      }
      printf("%s", s[index1]);
    }
  }
}
// 好吧，是我理解错意思了，他的意思是找到所有的到这些输入中的最小值而不是说从输入中输出一个hamming最小值。。。
