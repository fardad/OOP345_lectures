// initializer.cpp
#include <iostream>
using namespace std;
class Student {
   int m_stid;
   double m_gpa;
public:
   Student(int stid = 0, double gpa =4.0);
};


int main() {
   int n0 = 7;   // C-style
   int n1 = 7.2; // C-style - narrowing (loss of information)
   int n2{ 6 };   // braces: type-safe universal form
   int n3 = { 5 }; // same as above, '=' is redundant

   Student S{ 234, 3.5 };

   int i{};
   double* d{};
   Student st{};

   cout << "n0 = " << n0 << endl;
   cout << "n1 = " << n1 << endl;
   cout << "n2 = " << n2 << endl;
   cout << "n3 = " << n3 << endl;
   return 0;
}