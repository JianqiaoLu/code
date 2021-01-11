// #include<stdio.h> 
// #include<math.h> 
// int main()
// { 
   
//    int c, q = 1;
//    while (c = getchar() != EOF)
//     {
//      printf("%s", q ? "``" : "''") ;
//      printf("\n");
//      q    = !q; 
//    }
   
// // }
// // // 无所谓了，我只要知道这个是怎么做的就行奥里给。
// #include<stdio.h> 
// #include<math.h> 
// char s[] =  "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
// int main()
// { 
//   int i, c;
//   while ((c = getchar()) != EOF)
//   {
//     /* code */
//     for (int i = 0; i < strlen(s); i++)
//     {
//       /* code */
//       if (s[i] == c  )
//       {
//         /* codincludee */
//         printf("%s",s[i - 1]);
//         break;

//       }
//       else
//       {
//          printf("%c", c);
//          break;
//       }
       
//     }
    

//   }
   
// }
// int example(){

//    int i,c;
//    while (c = getchar() != EOF)
//    {
//      /* code */
//      for (int i = 0; s[i] && s[i]!= c ; i++)
//      {
//        /* code */
//      }
//      if (s[i]) putchar(s[i-1]);
//      else
//      {
//        putchar(c);
//      }
     
     
//    }




// // }
// #include<stdio.h> 
// #include<math.h> 
// #include<string.h>
// const char* rev  = "fdasfsadfsdakjlkfasjdlfjsadkfjlk";
// const char* res[]  = {"1","2","3", "fsda"};
// char r(char a) {

//     return rev[ a - 'A'];
  
// }
// int main()
// { 
//   int p = 1, q = 1; 
//   char s[30];
//   while (scanf("%s", s));
//     {
//        int len = strlen(s);
//        for (int i = 0; i < len; i++)
//        {
//            if (s[i] != s[len - i]) p = 0;
//            if (r(s[i]) !=  s[len -i ]) q = 0; 
//        }
//        int result  = p + 2* q ;
//        printf("%s is a %s" , s, res[result] );
//     }
  
  
// }
#include<stdio.h> 
#include<math.h> 
#include<string.h> 
int main()
{ 
  int n ;
  scanf("%d", &n);
  printf("\n");
  int ans[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &ans[i]);
  }

  printf("\n");
  for (;;)
  {
    int b[n], A = 0, B = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &b[i]);
      if (b[i] == ans[)
        A++;
    }
    if (b[0] == 0)
      break;
    for (int i = 0; i < 9; i++)
    {

      int a1 = 0, a2 = 0;
      for (int j = 0; j < n; j++)
      {
        /* code */
        if (ans[j] == i)
          a1++;

        if (b[j] == i)
          a2++;
      }
      int sub = (a1 < a2) ? a1 : a2;
      B += sub;
    }
    printf("( %d , %d)", A, B);
  }
}
/* code */
