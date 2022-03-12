#include "headl.h" 
class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i < num; i++)
        {
            int a = i;
            int b = 0;
            while (a!=0)
            {
                b += a%10;
                a /= 10;
            }
            if(b%2==0) ans ++;
            
        }
        return ans;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  a->countEven(30);
  
}
