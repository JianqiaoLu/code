// #include <iostream>
// #include <tuple>

// using namespace std;

// struct result
// {
//   bool x; string y;
// };

// result foo(){
//   return {true,"hello"};
// }
// int main() {

//     auto [a, b] = foo();
//     cout << a<< ", " << b << ", " <<  endl; 
//     return 0;

// }
// auto + structure binding真的无敌
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 1000;
      
struct coordi
{
  /* data */
  int x;
  int y;
};

coordi calco(char s, coordi xy)
{

  auto [x, y] = xy;
  if (s == 'L') x--;
  else if (s == 'R') x++;
  else if (s == 'U') y++;
  else if (s == 'D') y--;
  else
  {
    x = -1;
    y = -1;
  }
}

int legal(coordi xy)
{
  auto [x, y] = xy;
  if ((x < 0 || x > 5) || (y < 0 || y > 5))
    return 0;
  else
    return 1;
}
int main()
{
  int qipan[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  char s[maxn];
  scanf("%s", s);
  int length = strlen(s);
  int x = 1, y = 2;
  coordi xy = {x, y};
  for (int i = 0; i < length; i++)
  {
    coordi xy2 = calco(s[i], xy);
    auto [x1, y1] = xy2;
    if (legal(xy2))
    {
      swap(qipan[x][y], qipan[x1][y1]);
      xy = {x1, y1};
    }
    else
    {
      printf("This puzzle has no final configuration");
    }
  }
  printf("%s", qipan);
}
