
#include <iostream>
#include "foo.h"

using sdds::faa;

int whatever(){
   faa();
   std::cout << "Whatever" << std::endl;
   
   {
      int i;


      // i dies here
   }

}