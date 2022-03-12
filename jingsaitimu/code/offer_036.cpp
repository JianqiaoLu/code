#include "headl.h" 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> a;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (isdigit(tokens[i][tokens[i].size() - 1]))
            {
                int b = 0, n = tokens[i].size();
                if (tokens[i][0] == '-')
                {
                    for (int j = n - 1; j > 0; j--)
                    {
                        b += (tokens[i][j] - '0') * pow(10, n - 1 - j);
                        
                    }
                    b = 0 - b;
                }
                else
                {
                    for (int j = n - 1; j >= 0; j--)
                    {
                        b += (tokens[i][j] - '0') * pow(10, n - 1 - j);
                    }
                }
                a.push(b);
            }
            else
            {
                int b = 0;
                if (tokens[i] == "+")
                {
                    b += a.top();
                    a.pop();
                    b += a.top();
                    a.pop();
                }
                else if (tokens[i] == "-")
                {
                    b -= a.top();
                    a.pop();
                    b += a.top();
                    a.pop();
                }

                else if (tokens[i] == "/")
                {
                    int ab = a.top();
                    a.pop();
                    b = a.top();
                    a.pop();
                    b = b / ab;
                }

                else
                {
                    b = 1;
                    b *= a.top();
                    a.pop();
                    b *= a.top();
                    a.pop();
                }
                a.push(b);
            }
        }
        return a.top();
    }
};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    vector<string> b = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    Solution* a = new Solution();
    a->evalRPN(b);

}
