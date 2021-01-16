#include <stdio.h>
#include <math.h>
#include <string>

#include <iostream>
using namespace std;
int main()
{
  string s1("hello!world");
  char s2[100] = "hello word";
  for (char s : s1)
    if (ispunct(s))
    {
    }
    else
    {
      cout << s << " ";
    }
}
