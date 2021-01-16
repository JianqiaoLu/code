// #include <iostream> // #include <map> // using namespace std; // int main() { // typedef pair< const char*, int> Key; // typedef map< Key , const char*> Mapa; // Key p1  = make_pair("Apple", 45); // Key p2 ("Berry", 20); // Mapa mapa; // mapa.insert({p1, "Manzana"}); // mapa.insert({p2, "Arandano"}); // return 0; // }
#include<stdio.h> 
#include<math.h> 
#include<string.h> 

int main()
{ 
  int a = 127;
  for (int i = 7; i >= 0 ; i--)
  {
    printf("%d", a & 1<< i);
  }
    
}
