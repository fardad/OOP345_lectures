#include <iostream>
using namespace std;

class Person;

class Title {
   string titlename;
   Person* givenTo[100]{};
   unsigned int num{};
public:
   Title(string title = "") :titlename(title) {
   }
   void giveto(Person* person) {
      if (num < 100) givenTo[num++] = person;
   }
};


class Person {
   struct {
      string frist;
      string last;
   } name;
   Person* marriedTo{};
   Title tlt;
   //Person marriedTo; like forward declaraion only pointers and refs are allowed
public:
   Person(string first, string last, Title ttl) :name{ first, last }, title{ ttl } {}

};
