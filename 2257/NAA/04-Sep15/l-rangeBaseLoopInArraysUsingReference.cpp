// range_for.cpp
#include <iostream>
using namespace std;

int main() {
   int a[]{ 1, 2, 3, 4, 5, 6 };

   for (int& e : a)
      e += 10;
   for (int e : a)
      cout << e << " ";
   cout << endl;
   return 0;
}