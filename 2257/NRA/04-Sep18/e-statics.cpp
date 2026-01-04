// class_static.cpp
#include <iostream>
using namespace std;

class Counter {
   int attr{};
   static int count;
public:
   Counter() { ++count; }
   ~Counter() { --count; }
   void print() { cout << getCount() << endl; }
   static int getCount() { return count; }
};

int Counter::count = 0;

int main() {
   cout << Counter::getCount() << endl;
   Counter a, * b{ new Counter };
   cout << Counter::getCount() << endl;
   cout << a.getCount() << endl;
   cout << b->getCount() << endl;
   delete b;
   cout << Counter::getCount() << endl;
   return 0;
}