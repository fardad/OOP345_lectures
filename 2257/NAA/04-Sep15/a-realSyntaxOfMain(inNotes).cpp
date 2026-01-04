#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
   cout << "04-Sep15 OOP345NAA" << endl;
   for (int i = 0; i < argc; i++) {
      cout << (i + 1) << ": " << argv[i] << endl;
   }
   return 0;
}