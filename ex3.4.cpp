#include<stdio.h> 
#include<math.h>
#include <string.h>
int sub(int ans[100], int s)
{
  int index = 0;
  for (int i = 2; i < s; i++)
  {
    if (not(s % i))
    {
      ans[index++] = i;
    }
  }
  return index;
}

int main()
{
  char a[80];
  scanf("%s", a);
  int ans[100];
  int index = sub(ans, strlen(a));
  int circle = 0;
  for (int i = 0; i < index; i++)
  {

    bool flag = true;
    int xunhuan = strlen(a) / ans[i];
    for (int k = 1; k < xunhuan; k++)
    {
      for (int j = 0; j < ans[i]; j++)
      {
        if (a[j] != a[j + k*ans[i]])
        {
          flag = false;
        }
      }
    }
    if (flag)
    {
      printf("%d", ans[i]);
      break;
    }
  }
}
