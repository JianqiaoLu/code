#include "headl.h" 
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> c;
        int l = 0, r = 0, n = pushed.size();
        while (l < n)
        {
            if(pushed[l] == popped[r])
            {
                l ++ ; r ++ ;
            }
            else if (!c.empty() and c.top() == popped[r])
            {
                c.pop();
                r ++ ;
            }
            else
            {
                c.push(pushed[l]);
                l ++ ;
            }
        }
        while (!c.empty())
        {
            if (c.top()  == popped[r])
            {
                r ++ ;
                c.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  vector<int> b = {2,1,0};
  vector<int> c = {1,2,0};
  a->validateStackSequences(b,c);
  
}
