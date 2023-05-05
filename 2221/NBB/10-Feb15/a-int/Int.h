#pragma once
#ifndef INT_H__
#define INT_H__
#include <iostream>
#include <string>
class Int {
   int m_value = 0;
   std::string m_message;
   auto valid() -> bool;
public:
   Int(int value = 0);
   auto get(std::istream& istr)->std::istream&;
   auto put(std::ostream& ostr) const->std::ostream&;
   // todo
   //operator int()const
};
auto operator<<(std::ostream& ostr, const Int& I)->std::ostream&;
auto operator>>(std::istream& istr, Int& I)->std::istream&;
#endif