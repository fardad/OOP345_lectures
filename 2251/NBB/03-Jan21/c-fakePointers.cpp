#include <iostream>
#include "pointers.h"
using namespace std;
int main( ) {
   cout << "OOP345NBB Jan 21" << endl;
   int num = 100;
   int pointer ptr = addressOf num;
   cout << num << endl;
   targetOf ptr = 400;
   cout << num << endl;
   cout << targetOf ptr << endl;
   return 0;
}