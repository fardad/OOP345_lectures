#include <string>
#include <exception>
#ifndef VALIDATION_H__
#define VALIDATION_H__
class badIntExp :public std::exception {
protected:
   std::string m_message = "Invalid Integer Number";
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
   virtual void operator()(int val) = 0;
};


class ValidAge:public Validation {
public:
   void operator()(int val);
};


class ValidMark :public Validation {
public:
   void operator()(int val);
};
#endif // ! VALIDATION_H__
