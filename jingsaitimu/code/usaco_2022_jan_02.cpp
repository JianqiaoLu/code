#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<iostream>  
#include<algorithm> 
#include<map> 
#include<vector> 
#include<cctype> 
#include<queue> 
#include<stack>
#include <sstream> 
using namespace std;
vector<int> A(4, 0);
vector<int> B(4, 0);
vector<int> C;
vector<vector<int>> D;
bool win1(int l, int r)
{
    vector<int> a1 = D[l];
    vector<int> a2 = D[r];
    int win = 0, loss = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a1[i] > a2[j]) win++;
            else if (a1[i] < a2[j]) loss++;
        }
    }
    return win > loss;
}
int get2()
{
    for (int a = 1; a <= 10; a++) for (int b = 1; b <= 10; b++) for (int c = 1; c <= 10; c++) for (int d = 1; d <= 10; d++) {
        C = { a,b,c,d };
        D = { A,B,C };
        if ((win1(0, 1) and win1(1, 2) and win1(2, 0)) or (win1(1, 0) and win1(0, 2) and win1(2, 1)))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::fill(A.begin(), A.end(), 0);
        std::fill(B.begin(), B.end(), 0);
        int v;
        for (int i = 0; i < 4; i++)
        {
            cin >> v;
            A[i] = v;
        }
        for (int i = 0; i < 4; i++)
        {
            cin >> v;
            B[i] = v;
        }
        if (get2()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
