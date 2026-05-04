#include <iostream>
using namespace std;


int main( ) {
   cout << "13-Mar13-OOP345NBB" << endl;
   char name[50] = "Fardad";
   int a[10] = { 10, 20, 30, 40, 50, 60 };
   char* cp = name;
   int* ip = a;
   cout << reinterpret_cast<size_t>(cp) << endl;
   cout << reinterpret_cast<size_t>(name) << endl;
   cout << reinterpret_cast<size_t>(ip) << endl;
   cout << reinterpret_cast<size_t>(a) << endl;
   cp += 2;
   ip += 2;
   cout << "======================================" << endl;
   cout << reinterpret_cast<size_t>(name) << endl;
   cout << reinterpret_cast<size_t>(cp) << endl << endl;
   cout << reinterpret_cast<size_t>(a) << endl;
   cout << reinterpret_cast<size_t>(ip) << endl;

   return 0;
}
