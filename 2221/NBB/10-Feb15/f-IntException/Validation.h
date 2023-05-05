#include <string>
#include <exception>
#ifndef VALIDATION_H__
#define VALIDATION_H__
class badIntExp :public std::exception {
protected:
   string m_message = "Invalid Integer Number";
public:
   const char* what()const noexcept;
};
class tooYoungExp : public badIntExp {
public:
   tooYoungExp();
};
class tooOldExp : public badIntExp {
public:
   tooOldExp();
};
class badMark : public badIntExp {
public:
   badMark();
};


class Validation {
protected:
   int noOfValidations = 0;
public:
   virtual void operator()(int val, std::string& messageOut) = 0;
};


class ValidAge:public Validation {
public:
   void operator()(int val, std::string& messageout);
};


class ValidMark :public Validation {
public:
   void operator()(int val, std::string& messageout);
};
#endif // ! VALIDATION_H__
