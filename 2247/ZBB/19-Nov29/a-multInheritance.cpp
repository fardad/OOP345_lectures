#include <iostream>
using namespace std;
class B1 {
   int data;
public:
   B1( int v = 0 ) :data( v ) {
      cout << "[CB1: " << data << "]\n";
   }
   virtual ~B1( ) {
      cout << "[~B1: " << data << "]\n";
   }
   virtual ostream& show( ostream& os )const {
      return os << "[B1: " << data << "]";
   }
};
ostream& operator<<( ostream& os, const B1& B ) {
   return B.show( os );
}
class B2 {
   int data;
public:
   B2( int v = 0 ) :data( v ) {
      cout << "[CB2: " << data << "]\n";
   }
   virtual ~B2( ) {
      cout << "[~B2: " << data << "]\n";
   }
   virtual ostream& show( ostream& os )const {
      return os << "[B2: " << data << "]";
   }
};
ostream& operator<<( ostream& os, const B2& B ) {
   return B.show( os );
}

class Derived :public B1, public B2 {
   int data;
public:
   Derived( int v = 100 ) :B1( v + 1 ), B2( v + 2 ), data( v ) {
      cout << "[CD: " << data << "]\n";
   }
   virtual ~Derived( ) {
      cout << "[~D: " << data << "]\n";
   }
   virtual ostream& show( ostream& os )const {
      B1::show( os );
      B2::show( os );
      return os << "[D: " << data << "]";
   }
};
int main( ) {
   Derived D( 200 );
   cout << (B1&)D << endl;
   cout << (B2&)D << endl;
   return 0;
}