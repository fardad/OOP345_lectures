#include <cmath>
#include "Circle.h"

Circle::Circle(double radius) :m_radius{ radius } {}

double Circle::area() const{
   return 3.14159265 * m_radius * m_radius;
}
bool Circle::operator==(const Shape& S) const {
   const Circle* sptr = dynamic_cast<const Circle*>(&S);
   return sptr ? std::abs(m_radius - sptr->m_radius) < 0.00001 : false;
}

Shape* Circle::clone( ) const {
   return new Circle( *this );
}

std::ostream& Circle::display(std::ostream& ostr) const{
   ostr.setf(std::ios::fixed);
   ostr.precision(4);
   return ostr << "Circle(" << area() << ")" << std::endl;
}
