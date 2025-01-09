
#include <iostream>
#include <functional> 
#include <vector>
using namespace std;
/*
In C++, a std::reference_wrapper is a utility from the <functional>
library that provides a way to create objects that behave like
references.

This is especially useful when you need to store references in standard
containers like std::vector, which normally only stores copies of
objects, not references.

Why Use std::reference_wrapper?
Standard containers like std::vector, std::list, etc., store objects
by value, which means they create copies.

std::reference_wrapper allows you to store references in these
containers without copying the original objects.

*/

int main( ) {
   int a = 10;
   int b = 20;

   // Create reference wrappers
   std::reference_wrapper<int> refA = a;
   std::reference_wrapper<int> refB = b;

   // Modify the original variables through the reference wrappers
   refA.get( ) = 15;
   refB.get( ) = 25;

   std::cout << "a: " << a << ", b: " << b << std::endl; // Output: a: 15, b: 25

   return 0;
}