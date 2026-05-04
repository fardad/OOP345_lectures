#include <iostream>

using namespace std;
int main() {
   cout << "OOP345NBB - Jan 16" << endl;
   int i = 10;
   void* v = &i;                  // store address without type
   int* ip = static_cast<int*>(v); // cast back to int*
   cout << *ip << endl;           // safe access
   return 0;
}