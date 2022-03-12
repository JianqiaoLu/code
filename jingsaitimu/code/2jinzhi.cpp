#include "headl.h" 

int main()
{
    for (int i = 0; i < 8; i++)
    {
        string s = "";
        for (int j = 0; j < 3; j++)
        {
            if (i & (1 << j)) s.push_back('1');
            else s.push_back('0');
        }
     cout << s << endl;
    }
}
