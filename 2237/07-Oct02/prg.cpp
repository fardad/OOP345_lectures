#include <iostream>
using namespace std;

void sum(int mark, int bonus) {
   cout << (mark + bonus) << endl;
}
void prod(int qty, int price) {
   cout << "The product is " << (qty * price) << endl;
}

auto main() -> int {
   
   void (*funcptr)(int, int); // a pointer to function called "funcptr" that can hold the address of any
                              // function that returns a void and recieves two integers....
   funcptr = sum;
   funcptr(10, 10);

   funcptr = prod;
   funcptr(5, 50);

   return 0;
}
