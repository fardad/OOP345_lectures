// class_basic.cpp
#include <iostream>
using namespace std;

class Item {
   int id;          // private by default
public:
   Item(int i) : id(i) {}  // constructor
   void display() const { cout << "Item " << id << endl; }
};

int main() {
   Item a(1);
   a.display();
   return 0;
}