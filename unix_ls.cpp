#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<iostream>  
#include<algorithm> 
#include<map> 
#include<vector> 
#include<cctype> 
using namespace std; 
string filenames[1000];
void print(const string & s, int total, char extra)
{
  for (int i = 0; i < s.size(); i++)
  {
    cout<<s[i];
  }
  for (int i = 0; i < total - s.size(); i++)
  {
    cout<<extra;
  }
  return;
}
int main() 
{ 
  int n, maxn = 0;

  cin>>n;
  for (int i = 0; i < n; i++)
  {

    cin>>filenames[i];
    maxn =  maxn < (int)filenames[i].size() ? filenames[i].size(): maxn;
  }
  sort(filenames, filenames + n);
  int col, row;
  col = (20- (maxn ))/ (maxn + 2) + 1;
  row = n / col + 2;
  int k = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      print(filenames[k++], j  == col - 1 ? maxn + 2: maxn , ' ');
      if (k == n)
      {
        return 0;
      }
    } 
    cout<<endl;
  }
}
