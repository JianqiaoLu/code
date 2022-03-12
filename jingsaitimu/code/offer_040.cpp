#include "headl.h" 
class Solution {
public:
  int maximalRectangle(vector<string>& matrix) {
    if (matrix.size() ==0)
    {
      return 0;
    }
    
    int n = matrix[0].size(), ans = 0;
    vector<int> prev(n, 0);
    for (int i = 0; i < matrix.size(); i++)
    {
      vector<int> next(n, 0);
      for (int j = 0; j < n; j++)
      {
        if(matrix[i][j] == '1')  next[j] = prev[j] + 1;
      }
      ans = max(ans, largestRectangleArea(next));
      prev = next;
    }
    return ans;
  }
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(), ans = 0;
    stack<int> a;
    a.push(-1);
    a.push(0);
    for (int i = 1; i < n; i++)
    {
      while (a.top() != -1 and heights[i] < heights[a.top()])
      {
        int j = a.top();
        a.pop();
        ans = max(ans, heights[j] * (i - a.top() - 1));

      }
      a.push(i);
    }
    while (a.top() != -1)
    {
      int j = a.top();
      a.pop();
      ans = max(ans, heights[j] * (n - a.top() - 1));
    }
    return ans;
  }
};
int main()
{
  freopen("test_in.txt", "r", stdin);
  freopen("test_out.txt", "w", stdout);
  Solution* a = new Solution();

}
