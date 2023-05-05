#pragma once
#ifndef INT_H__
#define INT_H__
#include <iostream>
#include <string>
#include "Validation.h"

class Int {
   int m_value{ 0 };
   std::string m_message;
   Validation* m_valid;
public:
   Int(int value = 0, Validation* vldFunctor = nullptr);
   void set(Validation* vldFunctor = nullptr);
   auto get(std::istream& istr)->std::istream&;
   auto put(std::ostream& ostr) const->std::ostream&;
};
std::ostream& operator<<(std::ostream& ostr, const Int& I);
std::istream& operator>>(std::istream& istr, Int& I);

#endif