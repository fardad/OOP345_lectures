#include <iostream>
using namespace std;
#include "Stack.h"
#include "Employee.h"
int main() {
   Stack<double> d;
   d.push(1.2).push(2.3).push(3.5);
   while (d) {
      cout << d.pop() << endl;
   }
   Stack<Employee> E;
   E.push({ "Larry Burns", 11234 });  
   E.push({ "Carl Carlson", 212  34 });   
   E.push({ "Frank Grimes", 31234 });  
   E.push({ "Homer Simpson", 123 });
   while (E) {
      cout << E.pop() << endl;
   }
   return 0;
}