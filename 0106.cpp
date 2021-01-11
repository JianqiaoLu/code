// #include<stdio.h> 
// #include<math.h> 
// #include<string.h> 
// typedef struct 
// {
//   double x;
//   double y;
// } Point;

// int main()
// { 
//   Point p1 = {1,2};
//   printf("%f", p1.x);
// }

// #include<stdio.h> 
// #include<math.h> 
// #include<string.h> 
// long long calog(int m)
// {
//   long long ans = 1;
//   for (int i = 1; i <= m; i++)
//   {
//     ans = ans * i;
//   }
//   return ans;
// }

// int main()
// { 
//   int m=1,n=21;
//   long long ans = calog(n)/(calog(m) * calog(n-m));
//   printf("%f", ans);
// }

// long long factorial(int m, int n)
// {
//   long long ans = 1;
//   m  = (m < (n -m)) ? m : n -m;
//   for (int i = m + 1; i <= n ; i++)
//   {
//     ans *= i;
//   }
//   for (int i = 1; i < n -m + 1 ; i++)
//   {
//     ans /= i;
//   }
//   return ans;
// }

// int isprime(int n)
// {
//   if (n <= 1)
//   {
//     return 0;
//   }
//   int m = floor(sqrt(n) + 0.5) ;
//   int i;
//   for (i = 1; i <= m; i++)
//   {
//     if (n % i == 0)
//     {
//       break;
//     }
    
//   }
//   if (i == m + 1)
//   {
//      return 1;
//   }
//   else
//   {
//     return 0;
//   }
  
  
  
// }
#include<stdio.h> 
#include<math.h> 
#include<string.h> 
int swap(int* a, int* b){
  int  t= *a;
  *a = *b;
  *b = t;
  return 0;
}
int main()
{ 
  int a = 4;
  int b = 3;
  int ival =42;
  int* p = &ival ;
  float* p2 ;
  // 我的理解是，指针的初始化定义的时候可以接受地址，同时指针指向该地址存的值
  swap(&a,&b); 
}
// 你要想清楚的就是，指针的地址指向的并不是某一个值而已，而是整个变量！
// 所以你之前误以为 int a[] 和 *a是一个东西是由原因的，他们都是传递存放变量的首地址！
// 其实也就是再告诉你说，所有数组变量都是存储着受变量地址而已
int sum1(int* begin, int* end){
 int *p = begin;
 int ans =0;
 for (; p != end; p++)
 {
   ans += *p;
 }
 return ans;
}
int sum2(int* begin, int* end){
 int n = begin - end;
 int ans = 0;
 for (int i = 0; i < n; i++)
 {
  //  ans+= *(begin + i) ;
   ans += begin[i];
//  指针除了可以 +i,还可以通过begin[i]来访问 
 }
 return  ans;

}