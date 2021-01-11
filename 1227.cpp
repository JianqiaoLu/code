#include<stdio.h> 
#include<math.h> 
#define INF 1000000 
int main()
{ 
  int min = INF,max = -INF, n, k, kase = 0, s;
  while (scanf("%d", &n) == 1 && n )
  
  {
     min = INF;
     max = - INF;
     s  = 0;
   for (int j = 1; j <=  n; j++)
   { 

     /* code */
     
     scanf("%d", &k);
     s += k;
     if (k < min)
     {
       min = k;
     }
     if (k> max)
     {
       max = k;
     }
     
     
   }
   if (kase)
   {
     printf("\n");
     
   }
   printf(" case: %d,%d,%d,%.3f ", ++kase, min,max,(double)s/n);
  
   
  }

}
