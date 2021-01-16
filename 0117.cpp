#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<iostream>  
#include<algorithm> 
#include<map>
#include<vector>
#include<cctype>
using namespace std; 
map<string, int> cnt;
vector<string> words;

string repr(const string& s)
{
  string ans = s;
  for (int i = 0; i < ans.length(); i++)
  {
    ans[i] = tolower(ans[i]);
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() 
{ 
  string s;
  while (cin>> s)
  {
    if (s[0] == '#')
    {
      break;
    }
    words.push_back(s);
    string ans = repr(s);
    if (! cnt.count(ans) ) 
    {
      cnt[ans]  = 0;
    }
    cnt[ans] ++;
  }

vector<string> ans1;
for (int i = 0; i < words.size(); i++)
{
  if (cnt[repr(words[i] )] == 1)
  {
    ans1.push_back(words[i]);
  }
}
for (int i = 0; i < ans1.size(); i++)
{
  cout<<ans1[i]<<endl;
}

}

