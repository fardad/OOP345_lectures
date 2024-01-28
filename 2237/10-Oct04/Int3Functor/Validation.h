#include <string>
#ifndef VALIDATION_H__
#define VALIDATION_H__

class Validation {
protected:
   int noOfValidations = 0;
public:
   virtual bool operator()(int val, std::string& messageOut) = 0;
};

class ValidAge :public Validation {
   int m_minAge;
   int m_maxAge;
public:
   ValidAge(int min = 19, int max = 100);
   bool operator()(int val, std::string& messageout); // function call operator overloaded
};

class ValidMark :public Validation {
public:
   bool operator()(int val, std::string& messageout);
};
#endif

/*
NormalClass ns;

ns.foo();

ValidAge fn;

fn(20, "error message");  // has the function call operator overloaded.
fn.operator()(20, "error message");  // stupid, but does the samething as above





*/