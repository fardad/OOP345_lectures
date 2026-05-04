
#include <iostream>

using namespace std;


int main() {
   cout << "OOP345NBB - Jan 16" << endl;
   int a[]{ 1, 2, 3, 4, 5, 6 };

   for (int& e : a)
      cout << e++ << " ";
   cout << endl;
   for (int e : a)
      cout << e++ << " ";
   cout << endl;
   for (int e : a)
      cout << e << " ";
   cout << endl;
   return 0;
}