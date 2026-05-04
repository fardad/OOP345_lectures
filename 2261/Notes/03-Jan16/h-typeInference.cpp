#include <iostream>
using namespace std;
int main() {
   cout << "OOP345NBB - Jan 16" << endl;
   int a[]{ 1, 2, 3, 4, 5, 6 };
   const auto n = 6; // inferred as int
   unsigned long long* ptr;

   auto a = ptr;

   for (auto i = 0; i < n; i++)
      cout << a[i] << ' ';
   cout << endl;
   return 0;
}