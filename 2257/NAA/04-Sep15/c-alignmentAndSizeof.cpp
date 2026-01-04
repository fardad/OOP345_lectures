#include <iostream>
using namespace std;
struct rec1 {
   double a;
   double b;
};

struct rec2 {
   char a;
   int middle;
   double b;
};

struct alignas(16)rec3  {
   double a;
   double b;
};

int main(int argc, char* argv[], char* env[]) {
   cout << "04-Sep15 OOP345NAA" << endl;
   cout << "rec1: " << sizeof(rec1) << endl;
   cout << "rec2: " << sizeof(rec2) << endl;
   cout << "align rec1: " << alignof(rec1) << endl;
   cout << "align rec2: " << alignof(rec2) << endl;
   return 0;
}