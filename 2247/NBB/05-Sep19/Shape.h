#pragma once
#include <iostream>
class Shape {
public:
   virtual double area( )const = 0;
   virtual std::ostream& display( std::ostream& ostr = std::cout )const = 0;
   virtual bool operator==( const Shape& S )const = 0;
   virtual Shape* clone( )const = 0;
   virtual ~Shape( ) = default;
};
std::ostream& operator<<( std::ostream& ostr, const Shape& S );

