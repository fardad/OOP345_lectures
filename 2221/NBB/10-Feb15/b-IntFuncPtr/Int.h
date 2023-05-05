#pragma once
#ifndef INT_H__
#define INT_H__
#include <iostream>
#include <string>
class Int {
   int m_value = 0;
   std::string m_message;
   bool (*m_valid)(int value, std::string& messageOut);
public:
   Int(int value = 0, bool (*isValid)(int, std::string&) = nullptr);
   auto get(std::istream& istr)->std::istream&;
   auto put(std::ostream& ostr) const->std::ostream&;
   auto set(bool (*isValid)(int, std::string&)) -> void;
};
std::ostream& operator<<(std::ostream& ostr, const Int& I);
std::istream& operator>>(std::istream& istr, Int& I);
#endif