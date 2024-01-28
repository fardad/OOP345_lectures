#include <iostream>
using namespace std;

#ifdef sum
#  undef sum
#endif
#define sum(x, y) ((x) + (y))



int main() {
   int a = 2;
   int b = 5;
   int c{};

   std::cout << "The name of the source file    is " << __FILE__ << std::endl;
   std::cout << "The date of its pre-processing is " << __DATE__ << std::endl;
   std::cout << "The time of its pre-processing is " << __TIME__ << std::endl;

   c = sum(a, b) * 2; // 10
   cout << c << endl;

   cout << NULL << endl;
#ifdef NULL
# undef NULL
#endif
   // this is crazy and it is for "EXAMPLE" only
#define NULL 123  
   cout << NULL << endl;
   return 0;
}

// 999,999