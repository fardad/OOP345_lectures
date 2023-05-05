#include <list>
#include <iostream>
using namespace std;
#include "Employee.h"
int main() {
   list<Employee> E; 
   list<Employee>::iterator i;
   E.push_back({ "Larry Burns", 11234 });  
   E.push_back({ "Carl Carlson", 21234 });  
   E.push_back({ "Frank Grimes", 31234 });   
   E.insert(--E.end(), { "Homer Simpson", 123 });
   for (i = E.begin(); i != E.end(); i++)
      std::cout << *i << endl;
   E.erase(++E.begin());
   cout << "after erase" << endl;
   for (i = E.begin(); i != E.end(); i++)
      std::cout << *i << endl;
   std::cout << std::endl;
}