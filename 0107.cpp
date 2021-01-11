#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include <iostream>
using namespace std;
#include <algorithm>
bool sortchar(const char a, const char b)
{
  return a < b;
}
bool sortint(const int a, const int b)
{
  return a < b;
}
int main()
{ 
  char a[100],b[100];
  scanf("%s%s", a,b);
  int lena = strlen(a);
  int lenb = strlen(b);
  if (lenb != lena)
  {
    return false;
  }
  else
  {
    int chara[26], charb[26];
    memset(chara,0,sizeof(chara));
    memset(charb,0,sizeof(charb));
    for (int i = 0; i < lena; i++)
    {
      chara[a[i] - 'a']++;
      charb[b[i] - 'a']++;
    }
    sort(chara, chara + 26,sortint);
    sort(charb, charb + 26,sortint);
    for (int i = 0; i < 25; i++)
    {
      if (chara[i] != charb[i])
      {
        return false;
      }
      
    }
    return true;
  }
}
