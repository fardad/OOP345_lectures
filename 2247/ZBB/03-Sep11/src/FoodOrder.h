#pragma once
#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <iostream>
namespace seneca {
   class FoodOrder {
   };
   char* read( char delimiter = '\n', std::istream& istr = std::cin );
   extern double tax;
}

#endif // !SENECA_FOODORDER_H


