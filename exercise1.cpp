#include<stdio.h> 
#include<math.h> 
int main()
{ 
  // int a,b,c;
  // double avg;
  // scanf("%d%d%d", &a,&b,&c);
  // avg = (a+b+c) /3.0;
  // printf("%.3f",avg );
  // return 0;
  // int a;
  // double tep;
  // scanf("%d", &a);
  // tep = 5.0 * (a - 32) /9.0;
  // printf("%.3f",tep );
  // return 0;
  // int n;
  // double sum;
  // scanf("%d", &n);
  // sum = n * (n + 1 ) /2.0;
  // printf("%.3f",sum );
  // return 0;
  // if (true) if (false) printf("%d", 2);
  // else   printf("%d", 3);

  // return 0;
  // int n, price;
  // scanf("%d", &n);
  
  // price = n * 95;
  // if (price >= 300)
  //   price *= 0.85;
  // printf("%d", price);
  // double a,n;
  // const double pi = acos(-1.0);
  // scanf("%lf", &a);
  // n  = a * pi;
  // int b;
  // b = a * 1000;
  // b /= 1000;
  // printf("%f %f", sin(b), cos(b));
  int a,b,c,t;
  scanf("%d%d%d",&a ,&b,&c);
    if (a > b)
        { t  = b;
         b  = a;
         a  = t;
        }
    if (a > c)
    {
         t  = c;
         c  = a;
         a  = t;
    }
   if (b > c)
   {
         t  = c;
         c  = b;
         b  = t;
   }
   if (a*a + b*b ==  c*c )
     {printf("Yes");}
   else if (a+b<c)
   {
     printf("not a triangle");
   }
   else
   {
     
     printf("No");
     
   }
   
   
  


}
