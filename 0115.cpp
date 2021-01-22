#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<iostream>  
#include<sstream>
#include<algorithm> 
using namespace std; 
// int main() 
// { 
//  string line;
//  while (getline(cin,line))
//  {
//    int sum =0, x;
//    stringstream ss(line);
//    while (ss>>x) sum+= x;
//    cout<<sum;

//  }
   
// }
// struct Point
// {
//   int x;
//   int y;
//   Point(int x = 0, int y = 0): x(x), y(y){}
// };

// Point operator + (const Point& A, const Point& B)
// {
//   return Point(A.x + B.x, A.y + B.y);
// }

// ostream& operator<< (ostream & out, const Point& A)
// {
//   out<<"("<<A.x<<","<<A.y<<")";
// }
// // c++这个重写操作还是牛皮;
// template<typename T>
// T  sum(T* begin, T* end){
//   T ans = 0;
//   for (   ; begin != end; begin++)
//   {
//     ans = ans + *begin;
//   }
  
//   return ans;
// }

// int main()
// {
//   double a[] = {1.0, 2.2,3.3};
//   cout<<sum(a,a+3)<<"\n";
//   double b[] = {1231231,312312};
// }

// int main()
// {
//   int n, q, x ,a[100];
  
//   while (scanf("%d %d", &n, &q))
//   {
//     for (int i = 0; i < n; i++)
//     {
//       scanf("%d", &a[i]);
//     }
//     sort(a,a+n);
//     while (q--)
//     {
//       scanf("%d", &x);
//       int p = lower_bound(a,a+n,x) - a;
//       if (a[p] == x)
//       {
//         printf("在第%d个位置找到了 ",  p);
//       }
//       else
//       {
//         printf("没找到不好意思。。。");
//       }
//     }
    
    
//   }
  
// }

#include<vector>
vector<int> pile[100];
int n;
void find_block(int a, int& p, int* h)
{
  for (p  = 0;  p< n; p++)
  {
    for (h  = 0;  h < pile[p].size(); ++)
    {
      if (pile[p][h] == a)
      {
        return; 
      }
    }
  }
}
void moveover(int& p1, int& h1,int& p2);
int main()
{
  for (int i = h1+1; i < pile[p1].size(); i++)
  {
    pile[p2].push_back(pile[p1][i]);
  }
}
