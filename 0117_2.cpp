#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<iostream>  
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<vector> 
#include<cctype>
using namespace std; 
typedef set<int> Set;
map<Set,int> mapset;
vector<Set> vectorset;
int ID(Set s)
{
  if (mapset.count(s) )
  {
    return mapset[s];
  }
  vectorset.push_back(s);
  int id = vectorset.size() - 1;
  return id;
}
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
stack<int> Stack1;
int main() 
{ 
  int n;
  cin>> n;
  for (int i = 0; i < n; i++)
  {
    string op;
    cin>>op;
    if (op[0] == 'p') 
    {
      Stack1.push(ID(Set()));
    }
    else if (op[0] == 'D')
    {
      Stack1.push(Stack1.top());
    }
    else
    {
      Set x1 = vectorset[Stack1.top()];
      Stack1.pop();
      Set x2 = vectorset[Stack1.top()];
      Stack1.pop();
      Set x;
      if (op[0] == 'U')  
      {
        /* code */set_union (ALL(x1), ALL(x2), INS(x));
      }
      else if (op[0] == 'I')
      {
        (ALL(x1), ALL(x2), INS(x));
      }
      else
      {
        x = x2; x.insert(ID(x1)); 
      }
      Stack1.push(ID(x));

    }
   cout << vectorset[Stack1.top()].size() << endl; 
  }
   
}
