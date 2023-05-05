#pragma once
#ifndef INT_H__
#define INT_H__
#include <functional>
#include <iostream>
#include <string>
class Int {
   int m_value{};
   std::string m_message;
   std::function<bool(int, string&)>lamdaValid = nullptr;
public:
   Int(std::function<bool(int, string&)>lamdaValidArg = nullptr);
   void set(std::function<bool(int, string&)> lamdaValidArg);
   auto get(std::istream& istr)->std::istream&;
   auto put(std::ostream& ostr) const->std::ostream&;
};
std::ostream& operator<<(std::ostream& ostr, const Int& I);
std::istream& operator>>(std::istream& istr, Int& I);
#endif