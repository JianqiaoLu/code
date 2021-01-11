// // #include<stdio.h> 
// // #include<math.h> 
// // int main()
// // { 
// //   for (int i = 100; i < 1000 ; i++)
// //   {
// //     /* code */
// //     int m,n,k;
// //     m = i /100;
// //     n = i /10 %10;
// //     k = i%10;
// //     if (i == pow(m,3) + pow(n,3)+ pow(k,3))
// //     {
// //       printf("%d \n", i);
      
// //     }
    
// //   }
   
// // // }
// // #include<stdio.h> 
// // #include<math.h> 
// // int main()
// // { 


// //     for (size_t i = 1; ; i++)
// //     {
// //       int k,m,n;
// //       scanf("%d %d %d", &k,&m,&n);
// //       int human;
// //       for (human = 0; human <= 100; human++)
// //       {         
// //               if (human%3 == k && human%5 == m && human%7 == n)
// //               { 
 
// //                 printf("case %d : %d\n", i, human );
// //                 break;
                
// //               }
              
// //       }
// //       if (human == 101)      printf("case %d : No answer\n", i );
      

    
  
// //   }
// // }

    
// #include<stdio.h> 
// #include<math.h> 
// int main()
// { 
//   int n;
//   scanf("%d", &n);
  
//   for (int i = 1; i <= n; i++)
//   {
//     /* code */
//     for (int j = 1; j < i ; j++)
//     {
//       printf(" ");
//     }
    
//     for (int k = 1; k <= (n - i ) * 2 + 1  ; k++)
//     {
//       printf("*");
//     }
//     for (int m = 1; m < i  ; m++)
//     {
//          printf(" ");
//     }
//     printf("\n");
//   }
  
// }
// #include<stdio.h> 
// #include<math.h> 
// int main()
// { 
//   int i,j,k;
//   while (scanf("%d%d%d", &i,&j,&k )==1 && i + j + k );
  
//   {
//     /* code */
//     int a = (double)i/j * pow(10,k);
//     int b = pow(10,k);
//     double c = (double) a/b;
//     printf("%f", c  );
    
//   }
   
// }

// #include<stdio.h> 
// #include<math.h> 
// int main()
// { 
//    int a,b, kase = 0;
//    while (scanf("%d %d", &a,&b) && ( (a +b) || a*b) && a )
//    {
//       double sum = 0;
//       for (int i = a; i <= b; i++)
//       {
//        double aa = i;

//        sum +=  (double) 1.0/pow(aa,2);
//       }
//       if (kase) printf("\n");
      
//       printf("case%d: %.5f",++kase,sum);
      
//    }
     
// }

// #include<stdio.h> 
// #include<math.h> 
// int main()
// { 
//   for (int ss = 100; ss < 334 ; ss++) 
//  {
//   bool flag = true;
//   int sss = 2* ss, ssss =  *ss;
//   int a = ss/100, b = ss/10 % 10, c = ss %10;
//   int d = sss/100, e = sss/10 % 10, f = sss %10;
//   int g =  ssss /100, h =  ssss /10 % 10, m = ssss  %10;
//   int list1[9] = {a,b,c,d,e,f,g,h,m};
//   for (int x = 0; x < 8; x++)
//   { 
//     if (list1[x] == 0) break;
//     for (int y = x + 1; y <= 8; y++)  
//       {
//          if (list1[x] == list1[y] || not list1[y])
//          {
//            flag = false;
//            break;
//          }
         
//     }
//     if(not flag) break;
    
//   }

//   if (flag) printf("%d%d%d %d%d%d %d%d%d  ",a,b,c,d,e,f,g,h,m );
//  }

// }

  
   
// #include<stdio.h>
// int main()
// {
// int n;
// scanf("%d", &n);
// for(int i = 2; i <=2* n; i = i + 2)
// printf("%d\n", i);
// return 0;
// }
#include<stdio.h>
int main()
{
double i;
for(i = 0; i< 10; i += 0.1)
printf("%.1f\n", i);return 0;
}