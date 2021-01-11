#include<stdio.h> 
#include<math.h> 
#include<string.h> 
int r,c,n;
struct Command
{
  char c[4];
  int r1,c1,r2,c2;
  int a;
  int x[20];
}cmd[20];
int simulate(int* r0, int* c0)
{
  for (int i = 0; i < n; i++)
  {
    if (cmd[i].c[0] == 'E')
    {
      if (cmd[i].c1  == *c0 && cmd[i].r1 == * r0)
      {
        *r0 = cmd[i].r2;
        *c0 = cmd[i].c2;
      }
      else
      {
        *r0 = cmd[i].r1;
        *c0 = cmd[i].c1;
      }
      
    }
    else
    {
      int dr= 0, dc = 0;
      
      for (int j = 0; j < cmd[i].a; j++)
      {
        int x = cmd[i].x[j];
        if (cmd[i].c[0] == 'I' )
        {
           if (cmd[i].c[1] == 'R' && x<= *r0) dr++;
           if (cmd[i].c[1] == 'c' && x<= *c0) dc++;

        }
        else
        {
           if (cmd[i].c[1] == 'R' && x< *r0) dr--;
           if (cmd[i].c[1] == 'c' && x< *c0) dc--;
        }
      }
      
      *r0 += dr;
      *c0 += dc;
    }
  }
  return 1;
}

int main()
{ 
  int r0,c0,q,kase =0;
  while(scanf("%d%d$d", &r,&c,&n) == r && r)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%s", cmd[i].c);
      if (cmd[i].c[0] == 'E')
      {
        scanf("%d%d%d%d", &cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
      }
      else
      {
        scanf("%d", &cmd[i].a);
        for (int j = 0; j < cmd[i].a; j++)
        {
          scanf("%d", &cmd[i].x[j]);
        }
      }
    }
    if (kase)
    {
      printf("\n" );
    }
    printf("spredsheet # %d\n", ++kase);
    scanf("%d", &q);
     
    while (q -- )
    {
      scanf("%d%d", &r0,&c0);
      printf("%cell data in (%d,%d)", r0,c0);
      if (!simulate(&r0,&c0))
      {
        printf("Gone \n" );
        
      }
      else
      {
        printf("move to (%d,%d) \n", r0,c0);
      }
    }
  }
}
