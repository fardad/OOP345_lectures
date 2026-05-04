#include <iostream>
using namespace std;
struct Coor {
   int x;
   int y;
   int z;
};
int main() {
   cout << "OOP345NBB - Jan 16" << endl;
   cout << alignof(int) << endl;
   cout << alignof(double) << endl;
   cout << alignof(Coor) << endl;
   return 0;
}