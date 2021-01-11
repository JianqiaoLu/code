// #include<stdio.h> 
// #include<string.h>
// #include<math.h> 
// int a[100][100];
// int main()
// { 
//     int x, y,n, tot = 1;
//     scanf("%d", &n);
//     x = n - 1;
//     y = 0;
//     memset(a,0, sizeof(a));
//     int iter = 0;
//     a[x][y] = tot;
//     while (tot <  n * n){    
//         while(x+1 < n - iter)  {
//           a[++x][y] = ++tot;
//         } 
//         iter ++;
//         while( y - 1 >=  iter)  {
//           a[x][y--] = ++tot;
//         } 
//         iter ++;
//         while( x - 1 >=  iter)  {
//           a[x -- ][y]= ++tot;
//         } 
//         iter ++;
//         while( y + 1 < n -1 -  iter)  {
//           a[x ][y ++]= ++tot;
//         } 
//         iter ++;
//     } 
// }
#include<stdio.h> 
#include<math.h> 
#include<string.h>
int main()
{ 
  int count =0;
  char s[90],buf[99];
  scanf("%s" , s);
  for (int abc = 100; abc <= 999; abc++)
  {
    for (int de = 11; de <= 99; de++)
    {
      int x = abc * (de % 10);
      int y = abc * (de / 10);
      int z = abc * de;
      sprintf(buf, "%d%d%d%d", abc, de, x, y, z);
      // sprintf 这个还蛮好用的奥，用于讲一堆字符串输入到数组当中
      int ok = 1;
      for (int i = 0; i < strlen(buf); i++)
      {
        if (strchr(s, buf[i]) == NULL)
          ok = 0;
      }
      if (ok)
      {
        printf("<%d>\n", ++count);
        printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
      }
    }
  }
  printf("The number of solutions", count);
  return 0;
}
