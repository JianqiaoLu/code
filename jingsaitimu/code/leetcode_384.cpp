#include "headl.h" 
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
    Solution* a = new Solution();
    int ans1 = a->([1,null,3,2,4,null,5,6]);
}
   
}

class Solution {
public:
    vector<int> fixog;
    vector<int> changeog;

    Solution(vector<int>& nums) {
        for (auto i:nums)
        {
            fixog.push_back(i);
        }
        changeog = fixog;
        
        // vector<int>& og = nums;
    }
    
    
    vector<int> reset() {
        return fixog;
        // return nums;
    }
    
    vector<int> shuffle() {
        vector<int> tochange  ;
        tochange.assign(changeog.begin(), changeog.end());
        for ( int i = 0; i < tochange.size() - 1; i++)
        {
            int j = rand() % (tochange.size() - i)+ i;
            swap(tochange[i], tochange[j]);
        }
        return tochange;
    }
};