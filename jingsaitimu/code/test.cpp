#include "headl.h" 
#include <sstream>
void get(stringstream& ss)
{
  int a;
  ss >> a;
  if(ss.fail()) return;
  ss.ignore();
  cout<< a<<endl;
  get(ss);
}
int main()
{
  freopen("test_in.txt", "r", stdin);
  string  s = "100 2 3";
  stringstream ss;
  ss.str(s);
  get(ss);

}

