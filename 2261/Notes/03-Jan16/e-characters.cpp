#include <iostream>
using namespace std;
int main() {
   cout << "OOP345NBB - Jan 16" << endl;
   char c1 = 'A';
   char c2 = 'Z';
   cout << "Characters: " << c1 << " and " << c2 << endl;
   cout << "ASCII codes: " << static_cast<int>(c1)
      << " and " << static_cast<int>(c2) << endl;
   return 0;
}