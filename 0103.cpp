// #include<stdio.h>
// #include<math.h>
// #include<string.h>
// int main()
// {
//   int n;
//   while (scanf("%d", &n)  && 2 < n < 100000)
//   {
//     int x;
//     for (x = 2; x < n; x++)
//     {
//       int sum = x, y = x, ans[101], index= 0;
//       while (y / 11 != 0)
//       {
//         ans[++index] = y % 11;
//         y = y / 11;
//       }
//       ans[index] = y;
//       for (int i = 1; i <= index; i++)
//       {
//         sum += ans[i];
//       }
//       if (sum == n)
//         break;
//     }
//     if (x == n)
//       printf("%d", 1);
//     else
//       printf("%d", x);
//   }
// }
// // wonderful game bro
// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// int less(char *s, int p1, int p2)
// {
  // int len = strlen(s);
  // for (int i = 0; i < len; i++)
  // {
    // if (s[(p1 + i) % len] < s[(p2 + i) % len])
    // {
      // return 1;
    // }
  // }
  // return 0;
// }
// int main()
// {
  // int T;
  // scanf("%d", &T);
  // printf("\n");
  
  // char s[1000];
  // scanf("%s", s);
  
  // int ans = 0;
  // for (int i = 1; i < T; i++)
  // {
    // if (less(s, i, ans))
      // ans = i;
  // }
  // for (int i = 0; i < T; i++)
  // {
    // putchar(s[(i + ans) % T]);
  // }
// }
// 最重要的是要记住，getchar是一个一个字符输入，而sca是一直输入到空格出现结束字符串；
// #include<stdio.h> 
// #include<math.h> 
// #include<string.h> 
// int main()
// { 
  // int s[10];
  // s = getchar();
  // 
// }
// 
// #include<stdio.h> 
// #include<math.h> 
// #include<string.h> 
// int main()
// { 
//   char s[111];
//   scanf("%s", s);
//   printf("%s", s);
//   // 我想我应该搞清楚了char和int数组的区别了。。
  
  
// }