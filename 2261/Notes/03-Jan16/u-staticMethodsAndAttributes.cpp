
#include <iostream>
#include <utility>
using namespace std;
class Counter {
   static int count;
   int data;
public:
   Counter() { 
      ++count;
      data = 10;
   }
   ~Counter() { 
      --count; 
   }
   static int getCount() {
     // data = 10;
      return count; 
   }
};
int Counter::count = 0;

int main() {
   cout << "OOP345NBB - Jan 16" << endl;
   cout << Counter::getCount() << endl;
   Counter a, b;
   Counter* p = new Counter;
   cout << a.getCount() << endl;
   delete p;
   cout << b.getCount() << endl;
   return 0;

}