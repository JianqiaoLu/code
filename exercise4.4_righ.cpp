#include <stdio.h>
#include <math.h>
#include <string.h>
int map[3][6] = {{4, 0, 2, 3, 5, 1}, {3, 1, 0, 5, 4, 2}, {0, 2, 4, 1, 3, 5}};
void rotate(char *a, int p)
{
  char b[10];
  for (int i = 0; i < 6; ++i)
  {
    b[i] = a[i];
  }
  for (int i = 0; i < 6; i++)
  {
    a[i] = b[map[p][i]];
  }
}

int comp(char a[6], char b[6])
{
  for (int i = 0; i < 6; i++)
  {
    if (a[i] != b[i])
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  char a1[6];
  char a2[6];
  scanf("%s", a1);
  scanf("%s", a2);
  int flag = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        if (comp(a2, a1))
        {
          flag = 1;
          break;
        }
        rotate(a2, 2);
      }
      if (flag)
      {
        break;
      }
      rotate(a2, 1);
    }
    if (flag)
    {
      break;
    }
    rotate(a2, 0);
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
