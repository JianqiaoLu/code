#include<stdio.h> 
#include<math.h> 
#include<string.h> 
int qipan[10][10];

struct locate
{
  int x;
  int y;
};
int inqipan(locate l1)
{
  if (l1.x < 10 && l1.x >0 && l1.y < 10 && l1.y > 0 )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int inhorse(locate l1, locate l2){
   
   int disx = - (l1.x - l2.x);
   int disy = - (l1.y - l2.y);
   if (disx*disx + disy * disy == 5)
   {
     locate zuai ;
     if (disx > 0)
     {
       zuai.x = disx  -1 ; 
       /* code */
     }
     else
     {
       zuai.x = disx  + 1 ; 
     }
     if (disy > 0)
     {
       zuai.y = disy  -1 ; 
       /* code */
     }
     else
     {
       zuai.y = disy  + 1 ; 
     }
     
     if (inqipan(zuai))
     {
       return 0;
     }
     else
     {
       return 1;
     }
   }
   
   else
   {
     return 0;
   }
}
int inpao(locate l1, locate l2)
{
  locate juli;
  juli.x = l2.x - l1.x;
  int num = 0;
  juli.y = l2.y - l1.y;
  if (juli.x  == 0 || juli.y == 0 )
  {
    if (not juli.x)
    {
      for (int i = 1; i < juli.y; i++)
      {
        locate zuai;
        zuai.x = l1.x;
        zuai.y = i + l1.y;
        if (inqipan(zuai))
        {
          num ++;
        }
        
      }
      if (num ==1)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      
      
      
    }
    if (not juli.y)
    {
      
      for (int i = 1; i < juli.y; i++)
      {
        locate zuai;
        zuai.y = l1.y;
        zuai.x = i + l1.x;
        if (inqipan(zuai))
        {
          num ++;
        }
        
      }
      if (num == 1)
      {
        return 1;
      }
      else
      {
        return 0;
      }
      
      
    }
    
  }
  else
  {
    return 0;
  }
  
  
}
int inju(locate l1, locate l2)
{
  locate juli;
  juli.x = l2.x - l1.x;
  juli.y = l2.y - l1.y;
  if (juli.x  == 0 || juli.y == 0 )
  {
    if (not juli.x)
    {
      for (int i = 1; i < juli.y; i++)
      {
        locate zuai;
        zuai.x = l1.x;
        zuai.y = i + l1.y;
        if (inqipan(zuai))
        {
          return 0;
        }
        
      }
      return 1;
      
    }
    if (not juli.y)
    {
      for (int i = 1; i < juli.y; i++)
      {
        locate zuai;
        zuai.y = l1.y;
        zuai.x = i + l1.x;
        if (inqipan(zuai))
        {
          return 0;
        }
        
      }
      return 1;
    }
    
  }
  else
  {
    return 0;
  }
  
  
}


int main()
{ 
 memset(qipan, 0,sizeof(qipan));
}
