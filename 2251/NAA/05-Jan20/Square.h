#pragma once
#include "Shape.h"
class Square: public Shape{
   double m_side;
public:
   Square(double side);
   double area() const;
   bool operator==(const Shape& S)const;
   virtual Shape* clone( )const;
   std::ostream& display(std::ostream& ostr = std::cout)const;
};

