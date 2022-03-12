#include "headl.h" 
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
   
}

class Solution {
public:
    vector<int> togo ;
    int m1;
    int n1;

    Solution(int m, int n) {
        m1 = m;
        n1 = n;
        for (int i = 1; i < m * n + 1; i++)
        {
            togo.push_back(i);
        }
    }
    
    vector<int> flip() {
            int j = rand() % (togo.size()) ;
            vector<int> ans;
            ans.push_back(togo[j]/n1 - 1);
            ans.push_back(togo[j]%n1  );
            // togo.remove(togo.begin(),togo.end(),j);
            togo.erase(togo.begin()+j - 1);
            return ans;
    }
    
    void reset() {
        togo.clear();
        for (int i = 0; i < m1 * n1; i++)
        {
            togo.push_back(i);
        }
    }
};