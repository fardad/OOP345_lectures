#include <string>
#ifndef VALIDATION_H__
#define VALIDATION_H__

class Validation {
protected:
   int noOfValidations{ 0 };
public:
   virtual bool operator()(int val, std::string& errMessage) = 0;
};

class  ValidAge :public Validation {
public:
   bool operator()(int val, std::string& errMessage);
};

class ValidMark :public Validation {
   bool operator()(int val, std::string& errMessage);
};


#endif // ! VALIDATION_H__
