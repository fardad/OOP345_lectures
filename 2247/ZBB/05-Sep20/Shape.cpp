#include "Shape.h"

std::ostream& operator<<( std::ostream& ostr, const Shape& S ) {
   return S.display( ostr );
}
