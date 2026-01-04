
#include <iostream>
#include <utility>
using namespace std;
class Counter {
   int attr{};
   static int count;
public:
   Counter() { ++count; }
   ~Counter() { --count; }
   static int getCount() { return count; }
   void print() { cout << getCount() << endl; }
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