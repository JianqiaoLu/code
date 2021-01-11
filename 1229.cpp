#include<string.h>
#include<stdio.h> 
#include<math.h> 
#define maxn  100
int a[maxn];
int main()
{
  int n,k;
  memset(a,0,sizeof(a));
  scanf("%d%d", &n,&k);
  for (int i =1; i <= k; i++)
  {
    for (int j = 1; j <= n; j++)
    {
       if( j%i ==0 )   a[j] = !a[j];
    }
  }

 for (int i = 0; i <= n; i++)
 {
   if (i ==0)
   {
     printf("");
   }

  else
  {
   printf("%d", a[i]);
  }
 }
  
}