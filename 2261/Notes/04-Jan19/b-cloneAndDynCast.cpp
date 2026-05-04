#include <iostream>
using namespace std;
class Shape {
public:
   virtual double volume( ) const = 0;
   virtual Shape* clone( ) const = 0;   // polymorphic copy
   virtual ~Shape( ) = default;
};
class Cube : public Shape {
   double len{};
public:
   Cube( double l ) : len( l ) { }
   double volume( ) const override { return len * len * len; }
   Shape* clone( ) const override { return new Cube( *this ); }
};
class Sphere : public Shape {
   double rad{};
public:
   Sphere( double r ) : rad( r ) { }
   double volume( ) const override { return 4.18879 * rad * rad * rad; }
   Shape* clone( ) const override { return new Sphere( *this ); }
};
void displayVolume( const Shape* shape ) {
   if ( shape )
      cout << shape->volume( ) << endl;
   else
      cerr << "ERROR!" << endl;
}

// main.cpp
int main( ) {
   cout << "OOP345NBB - Jan 19" << endl;
   Shape* shape = new Sphere( 1.0 );
   Shape* shape1 = new Cube( 2.0 );

   Shape* clone = shape->clone( );

   displayVolume( shape );
   displayVolume( clone );

   Cube* c = dynamic_cast<Cube*>(shape1); // success, c will not be nullptr
   displayVolume( c );
   c = dynamic_cast<Cube*>(shape);
   displayVolume( c ); // this will display Error, since c will be nullptr
   delete shape;
   delete clone;

   clone = shape1->clone( );

   displayVolume( clone );

   delete clone;



   return 0;
}