#include<stdio.h> 
#include<string.h>
#define maxn 100
#include<math.h> 
using namespace std;
int a[maxn][maxn];
int main()
{
  int n;
  scanf("%dn", &n);
  memset(a,0,sizeof(a));
  int i = 0,j = n -1;
  int too = 1;
  int iter = 0;
  while (too <= n*n)
  
  {

      while ( i <n-iter)
      {
        a[i++][j] = too++;
      }
      i -- ; 
      too --;

      while (j>=0+iter)
      {
        a[i][j--]= too++;
      }
      j ++ ;

      too --;
      while (i>=0+iter)
      {
        a[i--][j] =  too++;
      }
      i ++;
      too --;

      while (j <n - iter - 1)
      {
        a[i][j++]= too++;
      }
      j --;
      too --;
      iter ++ ;
  }
  for( int x = 0; x < n; x++)
{
   for(int y = 0; y < n; y++) 
   {
     printf("%3d", a[x][y]);
     printf("\n");
} 
} 
}
