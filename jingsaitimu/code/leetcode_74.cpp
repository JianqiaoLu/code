#include "headl.h" 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        while (l < r - 1)
        {
            int m = l + (r - l) / 2;
            if (matrix[m][0] > target) r = m;
            else l = m;
        }
        int l1 = 0, r1 = matrix[l].size() - 1;
        while (l1 <= r1)
        {
            int m = l1 + (r1 - l1) / 2;
            if (matrix[l][m] == target) return true;
            else if (matrix[l][m] > target) r1 = m - 1;
            else l1 = m + 1;
        }
        if (r == matrix.size() - 1)
        {
            l1 = 0, r1 = matrix[r].size() - 1;
            while (l1 <= r1)
            {
                int m = l1 + (r1 - l1) / 2;
                if (matrix[r][m] == target) return true;
                else if (matrix[r][m] > target) r1 = m - 1;
                else l1 = m + 1;
            }

        }
        return false;
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<vector<int>> b{ {1,3,5,7},{10,11,16,20},{23,30,34,50}};
    Solution* a = new Solution();
    a->searchMatrix(b, 23);

}
