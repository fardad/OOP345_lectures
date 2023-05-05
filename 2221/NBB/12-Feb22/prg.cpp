#include <iostream>
using namespace std;
#include "Validated.h"
int main() {
   Validated<int> V = 5;
   V(10);
   V(15, '-');
   return 0;
}