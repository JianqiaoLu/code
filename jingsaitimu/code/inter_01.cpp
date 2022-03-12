#include "headl.h" 
class Solution {
public:
    bool isUnique(string astr) {
        int a = 0, n = astr.size(), di = 0;
        for (auto i: astr)
        {
            a |= 1 << (i - 'a');
        }
        for (int i = 0; i < 26; i++)
        {
            if((1 << i) & a)  di++;
        }
        return (di == n);
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
