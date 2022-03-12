#include "headl.h" 
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
        {
            return false;
        }
        
        pair<int, int> range = { 0, matrix[0].size() - 1 };
        while (range.first < matrix.size() and range.second >= 0)
        {

            int tocom = matrix[range.first][range.second ];
            if (tocom < target)
            {
                range.first++;
            }
            else if (tocom > target)
            {
                range.second--;
            }
            else
            {
                return  true;
            }
        }
        return false;

    }
}
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);

}
