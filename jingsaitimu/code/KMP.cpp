#include "headl.h" 
bool kmp(string a, string b)
{
  vector<int> next(b.size(), 0);
  for (int i = 1; i < next.size(); i++)
  {
    int loc = next[i - 1];
    while (loc != 0)
    {
      if (b[loc] == b[i])
      {
        next[i] = next[i - 1] + 1;
        break;
      }
      else loc = next[loc - 1];
    }
    if (!next[i]) next[i] = 0;
  }
  int l = 0, r = 0;
  while (r != b.size() and l != a.size())
  {
    if (r == 0 and a[l] != b[r]) { l++; }
    else if (a[l] == b[r])
    {
      l++;
      r++;
    }
    else r = next[r];
  }
  if (r == b.size())
  {
    return true;
  }
  else return false;
}
int main()
{
  freopen("test_in.txt", "r", stdin);
  freopen("test_out.txt", "w", stdout);
  bool ans = kmp("AAAAAABC", "AAC");
  int a = 1;
}
