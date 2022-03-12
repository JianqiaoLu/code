#include"headl.h" 
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    vector<int> ans;
    for (int i = 0; i < 32; i++)
    {
      if (n & (1 << i))  ans.push_back(1);
      else ans.push_back(0);
    }
    uint32_t ans2 = 0;
    for (int i = 0; i < ans.size(); i++)
    {
      ans2 += ans[i] << (31 - i);
    }
    return ans2;
  }
};
int main()
{
  freopen("test_in.txt", "r", stdin);
  freopen("test_out.txt", "w", stdout);
  Solution* a = new Solution();
  unit32_t  n = 00000010100101000001111010011100;
  a->reverseBits(n);
}
