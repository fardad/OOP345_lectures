
#include <iostream>
using namespace std;

int main() {
   std::cout << "The name of the source file    is " << __FILE__ << std::endl;
   std::cout << "The date of its pre-processing is " << __DATE__ << std::endl;
   std::cout << "The time of its pre-processing is " << __TIME__ << std::endl;
}