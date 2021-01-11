// #include<stdio.h> 
// #include<math.h> 
// #include<string.h> 
// int chance, left ;
// char ans[100], gs[100];
// int win , lose;
// 
// 
// void guess(char s){
  // int lenan = strlen(ans);
  // int bad = 1;
  // for (int i = 0; i < lenan; i++)
  // {
    // if (s == ans[i])
    // {
      // left --;
      // ans[i] = '_'; 
      // bad = 0;
    // }
  // }
  // if (bad)
  // {
    // chance --; 
  // }
// }
// 
// int main()
// {  
  //  int rnd; 
  //  char ans[100], gs[100];
  //  while (scanf("%d%s%s", &rnd, ans, gs) && rnd != -1)
  //  {
    //  win =0; 
    //  lose =0;
    //  chance = 7;
    //  left = strlen(ans);
    //  int lengs = strlen(gs);
    //  for (int i = 0; i < lengs; i++)
    //  {
      //  guess(gs[i]) ;
      //  if (not left)
      //  {
        //  win = 1;
        //  break;
      //  }
      //  else if (not chance)
      //  {
        //  lose = 1; 
        //  break;
      //  }
    //  }
    //  if (win)
    //  {
      //  printf("you win" );
    //  }
    //  else if (lose)
    //  {
      //  printf("you lose");
    //  }
    //  else
    //  {
      //  printf("you chickent out" );
    //  }
  //  }
// }
// 
#include<stdio.h> 
#include<math.h> 
#include<string.h> 
int a[100];
int n;
int go(int p1, int d, int iter){
  int p ;
  p =  p1;
  while (iter -- )
  {
    p = (p + d + n - 1)% (n) + 1 ;
    while (a[p] == 0)
    {
      p = (p + d + n - 1)% (n) + 1 ;
    }
  }
  return p ;
}

int main()
{ 
  int k,m;

  while (scanf("%d%d%d", &n, &k, &m))
  {
    int left = n;
    int p1 = 1, p2= n;
    for (int i = 1; i <= n; i++)
    {
      a[i]  =i;
    }
    while (left)
    {
       p1 = go(p1,1,k);
       p2 = go(p2,-1,m);
       left--;
       printf("%3d",p1 );
       a[p1] = 0;
       if (p2 != p1)
       {
          printf("%3d",p2 );
          a[p2] = 0; 
          left --;
       }
       printf("\n");
    } 
  }
  

   
}
