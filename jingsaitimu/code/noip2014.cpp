#include <cstdio>
#include<iostream>
#include<string.h>
#include<stdio.h> 

using namespace std;
 

int main(void) {
  freopen("test_in.txt", "r", stdin);
  freopen("test_out.txt", "w", stdout);
  int N =0 , m1 = 0, m2 = 0;
  while (scanf("%d %d %d", &N, &m1, &m2) == 3&& N != 0) {
    int p1[m1];
    int p2[m2 ];
    int poi1 = 0;
    int poi2= 0;
    int a  ;
    // string c;
    // getline(cin, c);
    // getline(int* p3[100], cin);
    for (int i = 0; i< m1 ; i++)
    {
        // cin >> a;
        scanf("%d", &p1[i]);
        // p1[i] = a;
    }
    for (int i = 0; i< m2 ; i++)
    {
        // cin >> a;
        scanf("%d", &p2[i]);
        // p2[i] = a;
    }
    for (int i = 0; i< N; i++)
    {
        if (p1[i%m1] < p2[i%m2])
           poi1 ++;
        else
        {
           poi2 ++;
            /* code */
        }
    }
    cout << poi1 << " " << poi2 << endl;
  }
  return 0;
}