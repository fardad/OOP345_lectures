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
   const Square* Sq = dynamic_cast<const Square*>(&S);
   return Sq ? abs( m_side - Sq->m_side ) < 0.00001 : false;
}

Shape* Square::clone( ) const {
   return new Square( *this );
}

