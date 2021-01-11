#include<stdio.h> 
#include<math.h> 
// int main()
// { 
//    for (int i = 1; i <= 9; i++)
//    {
//       for (int j = 0; j <= 9; j++)
//       {
//            int n =1100 * i + 11*j;
//            int m = sqrt(n);
//            if (floor(m*m + 0.5) == n)
//           //  注意这里为啥floor的是 加了0.5之后的数字。。因为我们需要保证floor向下取整的时候0.999 -> 1, 而不是0
//            {
//               printf("%d", n ); 
//            }
//       }
      
//    }
      
// }
// #include<stdio.h> 
// #include<math.h> 
// int main()
// { 
//   for (int x = 0; ; x++  )
//   {
//     int n = x*x;
//     if (n<1000) continue;
//     if (n > 9999) break;
//     int i = n /100;
//     int j = n % 100;
//     if (i/10 == i%10 && j/10 == j%10)
//     {
//       printf("%d", n);
      
//     }
    
      
    
//   }
//   return 0;
   
// }
// #include<stdio.h> 
// #include<math.h> 
// int main()
// {  
//    int iter = 0;
//    long n;
//    scanf(" %lld", &n);
   
//    while (n != 1)
//    {
//       if (n%2 == 0)
//       {
//         n  = n/2;
//       }
//       else
//       {
//         n = n*3 + 1;
//       }
//       iter += 1;
//    }
//   printf("%d", iter);
     
// }
// // 这个不对阿，你要考虑int不能超过多少，还有题目给出的输入值范围是多少

// #include<stdio.h> 
// #include<math.h> 
// int main()
// { 
//   int n = 1, iter = 1;
//   double sum = 0;
//   const double pi = acos(-1);
//   do
//   { 

//     sum += 1/n * pow(-1,iter + 1);
//     n += 2;
//     iter += 1;
//   } while (1.0/n >= 1e-6);
//   printf("%d", n);
  
     
// }

// #include<stdio.h> 
// #include<math.h> 
// #include<time.h>
// int main()
// { 
//   const int mod = 1000000;  
//   int i , sum = 0;
//   scanf("%d", &i);
//   for (int k = 1; k <=  i; k++)
//   {  
//     int factor = 1;
//     for (int m = 1; m <= k; m++)
//     {
//         factor *= m%mod;
//     }
//     sum = (sum + factor) % mod;
    
//   }
//   printf("%d\n", sum);

//   printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
  
   
// }

#include<stdio.h> 
#include<math.h> 
int main()
{ 
  int x, sum = 0, iter = 0,avg = 0,min = 0,max =0; 
  while (scanf("%d", &x))
  
  {
    iter += 1;
    sum+= x;
    if ( min >x) min = x;
    if (max  <x) max = x;
  
  }
  printf("%d %d %0.3f \n",min,max, (double)sum/iter);
  
  
}

