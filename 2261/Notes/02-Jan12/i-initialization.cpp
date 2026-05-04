// initializer.cpp
#include <iostream>
using namespace std;
class Student {
   //...
public:
   Student() = default;
   Student(const char* name, size_t stno, float gpa);
};
int main() {
   int n0 = 7;   // C-style
   int n1 = 7.2; // C-style - narrowing (loss of information)
   int n2{ 6 };   // braces: type-safe universal form
   int n3 = { 5 }; // same as above, '=' is redundant

   Student S{ "jack" ,234567, 3.5 };
   int i{};
   int* p{};
   Student X{};


   cout << "n0 = " << n0 << endl;
   cout << "n1 = " << n1 << endl;
   cout << "n2 = " << n2 << endl;
   cout << "n3 = " << n3 << endl;
   return 0;
}