
#include <iostream>
using namespace std;
struct dbls {
   double a;
   double b;
};
int main() {
   double* a = new double;
   a = new double; // memory leak

   return 0;
}