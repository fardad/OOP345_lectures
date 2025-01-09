#include "Square.h"
#include <cmath>
Square::Square( double side ) :m_side{ side } {
}

double Square::area( ) const {
   return m_side * m_side;
}
std::ostream& Square::display( std::ostream& ostr ) const {
   ostr.setf( std::ios::fixed );
   ostr.precision( 2 );
   return ostr << "Square[" << area( ) << "]";
}

bool Square::operator==( const Shape& S ) const {
   const Square* Sptr = dynamic_cast<const Square*>(&S);
   return Sptr? abs(m_side - Sptr->m_side) < 0.001: false;
}

Shape* Square::clone( ) const {
   return new Square( *this );
}
