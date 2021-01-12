#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<iostream>
using namespace std;
struct student
{
  int  cid;
  char  sid[5];
  char name[5];
  int scores[4] ,rank, total ; 
  double average;
  int del = 1;
} Spms[100];

int num = 0;
void print_menu()
{
  printf("Welcome to Student Performance Mnagement System (SPMS)" );
  
  printf("\n" );
  printf("1 - Add  \n" );
  printf("2 - Remove \n" );
  printf("3 - Query\n" );
  printf("4 - Show ranking\n" );
  printf("5 - Show Statistics\n" );
  printf("0 - Exit" );
  printf("\n");
  return ;
}

student scastu(){
  student s1;
  scanf("%s", s1.sid);
  scanf("%d", &s1.cid);
  scanf("%s", s1.name);
  for (int i = 0; i < 4; i++)
  {
    scanf("%d", &s1.scores[i]);
  }
  return s1;
}
void pristu(student s1){
  printf("%s", s1.sid);
  printf("%d", s1.cid);
  printf("%s", s1.name);
  for (int i = 0; i < 4; i++)
  {
    printf("%d", s1.scores[i]);
  }
}

int cal(student s1)
{
  int sum =0;
  for (int i = 0; i < 4; i++)
  {
    sum += s1.scores[i];
  }
  return 0;
}

int DQ(int seq)
{
  printf("lease enter SID or name, Enter 0 to finish");
  char an[100] ;
  scanf("%s", an);
  for (int i = 0; i < num; i++)
  {
    if (not Spms[i].del)
        {
          if ( Spms[i].sid == an)
          {
          if (seq)
          {
            pristu(Spms[i]);
            int   sum  = cal(Spms[i]); 
            Spms[i].total  =  sum;
            Spms[i].average = (double) sum /4;
            printf("%d %.2f",Spms[i].total, Spms[i].average );
            printf("\n" );
            return 0;
          }
          else
          {
            Spms[i].del = 1;
            printf("%s student(s)removed ", Spms[i].name );
            return 0;
          }
          }
    }
  }
  return 0;
}

void show()
{
  printf("加油加油");
}

int add()
{
  printf("Pleas enter the SID, CID, name and four scoures");
  printf("\n");
  student s1 = scastu();
  for (int i = 0; i < num; i++)
  {
    if (Spms[i].sid == s1.sid)
    {
      printf("duplicated sid");
      return 0; 
    }
  }
  Spms[num++] = s1;
  pristu(s1);
  printf("added successfully");
  return 1;
}

int main()
{ 
  int  s = 1;
  while (true)
  {
    print_menu();
    scanf("%d", &s);
    if (s == 0)
    {
      break;
    }
    else
    {
      if (s == 1)
      {
        add();
      }
      else if (s == 2)
      {
        int seq = 1;
        DQ(seq);
      }
      else if (s == 3)
      {
        int seq = 0;
        DQ(seq);
      }
      else if (s == 4)
      {
        printf("Please don't do that and it will hurt students" );
      }
      else if (s == 5)
      {
        show();
      }
    }
    
    
  }
  
  
}
