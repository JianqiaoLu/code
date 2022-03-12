#include "headl.h" 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size(), i = 0;
        while (i < j)
        {
            if (numbers[i] + numbers[j] > target) j --;
            else if (numbers[i] + numbers[j] < target) i ++;
            else return {i,j};
        }
        return {};
        
    }
};
int main() 
{ 
  freopen("test_in.txt", "r", stdin); 
  freopen("test_out.txt","w", stdout); 
  Solution* a = new Solution();
  
}
