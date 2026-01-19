#include <iostream>
using namespace std;
class Bclass;
class Aclass {
   Bclass* b;
   friend Bclass;
   Aclass( int a );
};


class Bclass {
   Aclass A;
public:
   Bclass( int a ) :A{ a } {

   }
   void foo( Aclass a );



};




int main( ) {
   cout << "Jun09 - OOP345NEE" << endl;

  

   return 0;
}