#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   cout << "|";
   cout.width(10);
   cout << "123" << "|" << endl;
   cout << "|" << setw(10) << "123" << "1" << endl;
   return 0; 
}