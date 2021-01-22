#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
vector<string> mtas;
int main()
{
  while (true)
  {
    string mta;
    map<string, vector<string>> gta;
    set<string> dupcheck;
    string sta = mta;
    if (dupcheck.count(sta))
    {
      continue;
    }
    dupcheck.insert(sta);
    if (!gta.count(sta))
    {
      mtas.push_back(mta);
      gta[sta] = vector<string>();
    }
    gta[sta].push_back(mta);
  }
}
