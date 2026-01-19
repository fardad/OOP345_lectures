#pragma once
#include "Shape.h"
class Circle : public Shape{
   double m_radius{};
public:
   Circle(double radius);
   double area() const;
   bool operator==(const Shape& S)const;
   virtual Shape* clone( )const;
   std::ostream& display(std::ostream& ostr = std::cout)const;
};

