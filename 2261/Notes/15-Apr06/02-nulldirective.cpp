// syntax.cpp
# define MESSAGE "Directive Syntax Example"  // Leading space is allowed

#include <iostream>

int main() {
   std::cout << MESSAGE << std::endl;
#                           // Null directive (ignored)
   return 0;
}