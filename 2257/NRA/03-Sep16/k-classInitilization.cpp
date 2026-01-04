// class_init.cpp
#include <iostream>
#include <string>
using namespace std;

class Item {
   int id = 0;               // default initializer
   string name{ "empty" };    // default initializer
public:
   Item() {}                               // uses defaults
   Item(const string& n) : name{ n } { }      // member list
   Item(const string& n, int i) : id{ i }, name{ n } {
      // too late to initilize anything, all attributes are create now.

   }
   void display() const { cout << name << " " << id << endl; }
};

int main() {
   Item a, b{ "apple" }, c{ "grape", 6 };
   a.display();
   b.display();
   c.display();
   return 0;
}