#include <iostream>
using namespace std;
class Shape {
public:
   virtual double volume( ) const = 0;  // pure virtual
   virtual ~Shape( ) = default;         // always good practice
};
class Cube : public Shape {
   double len{};
public:
   Cube( double l ) : len( l ) { }
   double volume( ) const override { return len * len * len; }
};
class Sphere : public Shape {
   double rad{};
public:
   Sphere( double r ) : rad( r ) { }
   double volume( ) const override { return 4.18879 * rad * rad * rad; }
};
void displayVolume( const Shape* shape ) {
   if ( shape )
      cout << shape->volume( ) << endl;
   else
      cerr << "ERROR!" << endl;
}
int main( ) {
   cout << "OOP345NBB - Jan 19" << endl;
   Shape* s1 = new Cube( 2.0 );
   Shape* s2 = new Sphere( 1.0 );

   displayVolume( s1 ); // Calls Cube::volume()
   displayVolume( s2 ); // Calls Sphere::volume()

   delete s1;
   delete s2;
   return 0;
}