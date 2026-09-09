#include <iostream>
using namespace std;
int main() {
   std::cout << "OOP345 NAA - Jun03" << endl;
   double result = [](int a, int b)->double { return a + b; } (10, 20);
   auto line = [](int len=70, char fill = '-') {
      for (int i = 0; i < len; i++, std::cout << fill); 
      std::cout << endl; 
   };

   line(20, '*');
   std::cout << result << endl;
   line(30, '#');
   return 0;
}