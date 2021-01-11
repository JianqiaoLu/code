#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
  char top[1000], ctop[1000];
  while (scanf("%s %s", top, ctop) == 2)
  {
    int kick1[1000], kick2[1000];
    memset(kick1, 0, sizeof(kick1));
    memset(kick2, 0, sizeof(kick2));
    int tlen = strlen(top);
    int blen = strlen(ctop);
    for (int i = 0; i < tlen; i++)
    {
      kick1[i] = (int)(top[i] - '0');
    }

    for (int i = 0; i < blen; i++)
    {
      kick2[i] = (int)(ctop[i] - '0');
    }
    int i, j;
    int ans1 = 0;
    int ans2 = 0;
    for (i = 0; i <= tlen; i++)
    {
      for (j = 0; j < blen; j++)
      {
        if ((kick1[i + j] + kick2[j]) >3)
         { break;}
      }
      if (j == blen)
       { ans1 = i;
          break;
       }
    }
    ans1 = (ans1 + blen > tlen) ? ans1 + blen : tlen;
    for (i = 0; i <= blen; i++)
    {
      for (j = 0; j < tlen; j++)
      {
        if ((kick2[i + j] + kick1[j]) >3)
          {break;}
      }
      if (j == tlen)
      {
        ans2 = i;
      break;
      }
    }
    ans2 = (ans2 + tlen >blen) ? ans2 + tlen : blen;
    int ans;
    ans = (ans1 > ans2) ? ans2 : ans1;
    printf("%d", ans);
    printf("/n");
    
  }
}
// 这解法先把输入作为字符串，然后把输入转化为数字属实给力strlen无敌， - ‘0’