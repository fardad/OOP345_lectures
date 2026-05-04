// object_macro.cpp
#define MAX_STUDENTS 100 // search and replace
//const int MAX_STUDENTS = 100; // location in memory
#include <iostream>

int main() {
   int classSize = MAX_STUDENTS;
   std::cout << "Max students: " << classSize << std::endl;
   return 0;
}