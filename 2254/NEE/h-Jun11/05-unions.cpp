#include <iostream>
#include <string>
using namespace std;
using namespace std;




class Employee {
   struct {
      string first;
      string middle;
      string last;
   } m_name;
};

union Data {
   int i;
   double f;
   char c;
};

int main( ) {
   Data D;
   D.i = 123;
   D.f = 456.5657; // this destroys content of i
   D.c = 'x';
   return 0;
}