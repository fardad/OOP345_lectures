#pragma once
#ifndef INT_H__
#define INT_H__
#include <iostream>
#include <string>
class Int {
   int m_value = 0;
   std::string m_message;
   auto (*m_valid)(int val,string& messageOut) -> bool = nullptr;
public:
   Int(int value = 0, auto (*validationLogicAddress)(int val, string& messageOut) -> bool = nullptr);
   void set(auto (*validationLogicAddress)(int val, string& messageOut) -> bool);
   auto get(std::istream& istr)->std::istream&;
   auto put(std::ostream& ostr) const->std::ostream&;
};
std::ostream& operator<<(std::ostream& ostr, const Int& I);
std::istream& operator>>(std::istream& istr, Int& I);
#endif