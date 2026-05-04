// file: exceptions.cpp
#include <iostream>
using namespace std;

void divide(double a[], int i, int n, double divisor) {
   if (i < 0 || i >= n)
      throw "Outside bounds";
   else if (divisor == 0)
      throw divisor;
   else
      a[i] = i / divisor;
}

int main() {
   bool keepdividing = true;
   double a[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 }, divisor;
   int i, n = sizeof a / sizeof a[0];

   do {
      try {
         cout << "Index: ";
         cin >> i;
         cout << "Divisor: ";
         cin >> divisor;
         divide(a, i, n, divisor);
         cout << "a[i] = " << a[i] << endl;
         cout << "Continuing ..." << endl;
      }
      catch (const char* msg) {
         cout << msg << endl;
         keepdividing = false;
      }
      catch (...) {
         cout << "Zero Division!" << endl;
         cout << "a[i] = " << a[i] << endl;
         cout << "Continuing ..." << endl;
      }
   } while (keepdividing);

   return 0;
}