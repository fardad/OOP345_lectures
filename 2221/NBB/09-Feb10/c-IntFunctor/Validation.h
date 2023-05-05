#include <string>
#ifndef VALIDATION_H__
#define VALIDATION_H__

class Validation {
protected:
   int noOfValidations = 0;
public:
   int tries()const;
   virtual bool operator()(int val, std::string& messageOut) = 0;
};

class ValidAge :public Validation {
public:
   bool operator()(int val, std::string& messageout);
};

class ValidMark :public Validation {
public:
   bool operator()(int val, std::string& messageout);
};
#endif