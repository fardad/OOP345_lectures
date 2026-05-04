#include <iostream>
#include <thread>
using namespace std;
void sayHello( ) {
   std::cout << "Hello from C++11 thread!\n";
}
int main( ) {
   thread t( sayHello );
   cout << "14-Mar17 - Multi processing!" << endl;
   t.join( );
   return 0;
}