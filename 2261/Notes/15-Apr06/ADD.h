#ifndef SENECA_ADD_H
#define SENECA_ADD_H

#ifdef ADD
#  undef ADD
#endif // ADD

#define ADD(x, y)  ((x) + (y)) // a safe compile error free macro definition.

#endif // !SENECA_ADD_H
