#pragma once
#include <iostream>
#include "Shape.h"
class Square :
    public Shape {
   double m_side;
public:
   Square( double side );
   virtual double area( ) const;
   virtual std::ostream& display( std::ostream& ostr = std::cout )const;
   virtual bool operator==( const Shape& S )const;
   virtual Shape* clone( )const;
};

