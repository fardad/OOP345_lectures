#include <iostream>
#include "Name.h"
using namespace sdds;
using namespace std;



// for practice 
// apply the rule of 5 to the name class and write a unit test for it.
// also overload ostream to print it with cout!!!

int main() { 

   Name A("Fardad");
   
   A.print() << endl;
   
   return 0;
}