// char.cpp
#include <iostream>
using namespace std;

int main() {
   char c1 = 'A';
   char c2 = 'Z';
   cout << "Characters: " << c1 << " and " << c2 << endl;
   cout << "ASCII codes: " << static_cast<int>(c1)
      << " and " << static_cast<int>(c2) << endl;
   c1++;
   c2--;
   cout << "Characters: " << c1 << " and " << c2 << endl;
   cout << "ASCII codes: " << static_cast<int>(c1)
      << " and " << static_cast<int>(c2) << endl;

   return 0;
}