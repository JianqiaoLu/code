#include "headl.h" 
#include <math.h>
class Solution {
public:
    int findNthDigit(int n) {
        int guess = 0;
        int low = 0, high = 9;
        while ((high - low) > 1)
        {
            int length = totaldigits(guess);
            if (length >= n)
            {
                high = guess;
                guess = (low + high) / 2;
            }
            else
            {
                low = guess;
                guess = (low + high) / 2;
            }
        }
        int length = totaldigits(low);
        int num = pow(10, low) + (n - 1 - length) / high ;
        string num1 = to_string(num);
        char i;
        if ((n - length) % high)
        {
            i = num1[(n - length) % high - 1];
        }
        else
        {
            i = num1[num1.length()-1];
        }
        return i - '0';
    }
    int totaldigits(int n)
    {
        int length = 0;
        for (int i = 1; i <= n; i++)
        {
            length += i * (pow(10, i) - pow(10, i - 1));
        }
        return length;
    }

};
int main()
{
    freopen("test_in.txt", "r", stdin);
    freopen("test_out.txt", "w", stdout);
    Solution* a = new Solution();
    // vector<int> aaa{ 1,2,3,5 };
    int ans1 = a->findNthDigit(9);
    int b = 1;

}