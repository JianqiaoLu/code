#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100][100];

int n, m;
int calvol(int height)
{
  int volumn = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] < height)
      {
        volumn += (height - a[i][j]) * 100;
      }
    }
  }
  return volumn;
}

void calans(int &vol, int &num, int heit)
{

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] <= heit)
      {
        vol += a[i][j] * 10 * 10;
        num++;
      }
    }
  }
}

double ans = 0;
int main()
{
  cin >> n >> m;
  int he = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      a[i][j] = he++;
    }
  }
  int floor;
  cout << "请输入一共有多少水分" << endl;
  cin >> floor;
  int volumn, heit;
  int max1 = floor/(100) ;
  for (heit = max1; heit >= 1; heit -- )
  {
    volumn = calvol(heit);
    if (volumn < floor)
    {
      break;
    }
    else if (volumn == floor)
    {
      ans = heit;
      break;
    }
  }
  if (ans != 0)
  {
    cout << "ans is " << ans << endl;
  }
  else
  {
    int num, vol;
    calans(vol, num, heit);
    ans = (double) (floor  + vol) / (num * 10 * 10);
    cout << "ans is " << ans << endl;
  }
}
