#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
  int a, b;
  while (scanf("%d %d", &a, &b))
  {
    int yu[100];
    int resi[100];
    int i;
    memset(yu, 0, sizeof(yu));
    memset(resi, 0, sizeof(resi));
    for (i = 0; i < b && !yu[a]; i++)
    {
      resi[i] = (int)a * 10 / b;
      yu[a] = i + 1;
      a = 10 * a % b;
      if (!a) break;
    }
    for (int j = 0; j <= i; j++)
    {
      if (resi[j] == a)
        printf("(");
      printf("%d", resi[j]);
    }
    if (a == 0)
    {
      printf("(0");
      i = yu[a];
    }
    printf(")");
    printf("reciper number is%d", i - yu[a] + 1);
  }
}

// using namespace std;
// int find(int *yushu, int index, int s)
// {
//   for (int i = 0; i < index; i++)
//   {
//     if (yushu[i] == s)
//     {
//       return 1;
//     }
//   }
//   return 0;
// }
// int main()
// {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   if (a % b == 0)
//   {
//     printf("直接整除%d", a / b);
//   }
//   else
//   {
//     int ans[100];
//     int yushu[100];
//     int index = 0;
//     int index2 = 0;
//     int a_1 = a;
//     int b_1 = b;
//     while (true)
//     {
//       int an = (a_1 * 10 / b_1);
//       int yu = (a_1 * 10 % b_1);
//       if (yu == 0)
//       {
//         printf("%f", (float) a/b);
//         break;
        
//       }
      
//       if (index2)
//       {
//         if (find(yushu, index2, yu))
//         {
//           printf("%d", index2);
//           break;
//         }
//       }
//       a_1 = a_1 * 10;
//       ans[index++] = an;
//       yushu[index2++] = yu;
//     }
//   }
// }
