#pragma once
#ifndef INT_H__
#define INT_H__
#include <iostream>
#include <string>
#include "validation.h"
class Int {
   int m_value = 0;
   std::string m_message;
   Validation* m_valid{};
   bool isValid{true};
public:
   Int(int value = 0, Validation* validationFunctor = nullptr);
   auto set(Validation* validationFunctor = nullptr)->void;
   auto get(std::istream& istr)->std::istream&;
   auto put(std::ostream& ostr) const->std::ostream&;
   operator bool()const;
};
std::ostream& operator<<(std::ostream& ostr, const Int& I);
std::istream& operator>>(std::istream& istr, Int& I);
#endif