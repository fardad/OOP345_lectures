#include <iostream>
using namespace std;
class Add {
   size_t noOfCalls{};
public:
   int operator()( int num1, int num2 ) {
      noOfCalls++;
      return num1 + num2;
   }
   size_t callNo( )const {
      return noOfCalls;
   }
};

int main( ) {
   Add add;
   cout << add( 123, 234 ) << endl;
   cout << add( 123, 234 ) << endl;
   cout << add( 123, 234 ) << endl;
   cout << add( 123, 234 ) << endl;
   cout << add( 123, 234 ) << endl;
   cout << add( 123, 234 ) << endl;
   cout << add( 123, 234 ) << endl;
   cout << add.callNo( ) << endl;
   return 0;
}
