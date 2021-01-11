#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
  while (true)
  {

    char s[2][100];
    for (int i = 0; i < 2; i++)
    {
      scanf("%s", s[i]);
    }
    int flag = 1;
    int slen = strlen(s[0]);
    int tlen = strlen(s[1]);
    int i = 0, j = 0;
    for (; i < slen && j < tlen;)
    {
      if (s[0][i] == s[1][j])
      {
        i++;
        j++;
      }
      else
      {
        j++;
      }
    }
    if (i == slen)
    {
      printf("yes");
    }
    else
      printf("no");
  }
}
