#pragma once
#ifndef INT1_H__
#define INT1_H__
#include <iostream>
#include <string>
class Int {
   int m_value{ 0 };
   std::string m_message;

   auto (*m_valid)(int val, std::string& errorMessage) ->bool;
public:
   Int(int value = 0, 
      auto (*validationFunction)(int,std::string&)->bool = nullptr);
   void set(auto (*validationLogicAddress)(int , std::string& ) -> bool);
  
   auto get(std::istream& istr)->std::istream&;
   auto put(std::ostream& ostr) const->std::ostream&;
};
std::ostream& operator<<(std::ostream& ostr, const Int& I);
std::istream& operator>>(std::istream& istr, Int& I);

#endif