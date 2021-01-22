// #include<stdio.h> 
// #include<math.h> 
// #include<string.h> 
// #include<iostream>  
// #include<algorithm> 
// #include<map> 
// #include<vector> 
// #include<cctype> 
// #include<set>
// #include<queue>
// #include<stack>
// using namespace std; 

// stack<int> q1;
// stack<int>  q2;
// set<int> Set;
// int a[] = {1, 2 ,5};
// int main() 
// { 
//   q1.push(1);
//   int j = 0; 
//   while (true)
//   {
//     int x = q1.top();
//     q1.pop();
//     if (!Set.count(x))
//     {
//       Set.insert(x);
//       q2.push(x);
//     }
    
//     for (int i = 0; i < 3; i++)
//     {
//       q1.push(x*a[i]);
//     }
//     int chouchou = q2.top();
//     q2.pop();
//     j ++;
//     if (j == 2)
//     {
//       cout<<chouchou<<endl;
//       break;
//     }
//   }
//   return 0;
  
// }

#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<iostream>  
#include<algorithm> 
#include<map> 
#include<vector> 
#include<cctype>
#include<assert.h> 
using namespace std; 
struct Biginter
{
  static const int BASE = 10;
  static const int WIDTH = 8;
  vector<int> s;
  Biginter(long long num = 0)
  {
    *this = num;
  }

  Biginter operator = (int num)
  {
    s.clear();
    do
    {
      s.push_back(num % BASE);
      num /= BASE;
    } while(num > 0) ;
    return *this;
  }
  
  Biginter operator = (const string& str)
  {
    s.clear();
    int x,len = (str.length() - 1);
    for (int i = 0; i < len; i++)
    {
      int end = str.length() - i * WIDTH;
      int start = max(0, end - WIDTH);
      sscanf(str.substr(start, end - start).c_str(), "%d",&x);
      s.push_back(x);
    }
    return *this;
  }
};

ostream& operator << (ostream& out,  const Biginter& b1  )
{
   for (int i = 0; i < b1.s.size(); i++)
   {
     out<<b1.s[i]<<endl;
   }
   return out;
   
}
vector<int> rvec;

int main()
{
  Biginter in1 = 123;
  cout<< in1;
}

// void random_fill(vector<int> & v,int a)
// {
//   for (int i = 0; i < a; i++)
//   {
//     v.push_back(rand());
//   }
  
// }

// ostream& operator << (ostream &in, vector<int> &v)
// {
//   for (int i = 0; i < v.size(); i++)
//   {
//     in<<v[i]<<endl;
//     assert(v[i]< v[i+1]);
//   }
//   return in;
  
// }

// int main() 
// { 
//   random_fill(rvec,4);
//   cout<<rvec;
// }
