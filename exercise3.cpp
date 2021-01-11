// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// int main()
// {
  // char s[80];
  // scanf("%s", s);
  // int score[strlen(s)];
  // memset(score, 0, sizeof(score));
  // for (int i = 0; i < strlen(s); i++)
  // {
    // if (not i)
    // {
      // if (s[i] == 'O')
        // score[i] = 1;
    // }
    // else
    // {
      // if (s[i] == 'O')
        // score[i] = score[i - 1] + 1;
    // }
  // }
// 
  // for (int i = 0; i < strlen(s); i++)
  // {
    // if (i == (strlen(s)- 1)) printf("%d", score[i]);
    // else
    // {
// 
      // printf("%d+", score[i]);
    // }
  // }
// }

// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// int ischar(char s)
// {
//   if (48 <= s &&  s <= 57)   return 1;
//   else
//   {
//     return 0;
//   }
// }
// int main()
// {
//   double zhiliang[4] = {12.01, 1.008, 16.00, 14.01};
//   char s[100];
//   scanf("%s", s);
//   int lenth = strlen(s);
//   double total = 0;
//   for (int i = 0; i < lenth; )
//   {
//     int num = 0;
//     double zl;
//     if (s[i] == 'C')
//       zl = 12.01;
//     elseif (s[i] == 'H')
//       zl = 1.008;
//     elseif (s[i] == 'O')
//       zl = 16.00;
//     elseif (s[i] == 'N')
//       zl =14.01;
//     else zl = '';
//     int index = i;
//     while (ischar(s[index + 1]) && index + 1 < lenth) index++;
//     if (index == i)  num = 1;
//     else
//     {
//       for (int j = i + 1; j <= index; j++)
//       {
//         num += ((int)(s[j] -48 )) * pow(10, index - j);
//       }
//     }
//     total += zl * num;
//     i = index + 1;
//   }
//   printf("%f", total);
  
// }
#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
  int ans[10];
  memset(ans, 0, sizeof(ans));
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    int x = i;
    while ((x / 10))
    {
      ans[x % 10]++;
      x = x / 10;
    }
    ans[x]++;
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%d:%d\n", i, ans[i]);
  }
  return 0;
}
