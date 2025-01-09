#pragma once
#include "Shape.h"
class Circle :
    public Shape {
   double m_radius{};
public:
   Circle( double radius );
   double area( ) const;
   std::ostream& display( std::ostream& ostr = std::cout )const;
   bool operator==( const Shape& S )const;
   Shape* clone( )const;
};

