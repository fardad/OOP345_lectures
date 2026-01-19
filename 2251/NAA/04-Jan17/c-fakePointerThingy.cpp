#include <iostream>
#include "pointers.h"
using namespace std;
int main( ) {
   int val;
   int pointer iptr;
   iptr = addressOf val;
   targetOf iptr = 1234;
   cout << val << endl;

   return 0;
}