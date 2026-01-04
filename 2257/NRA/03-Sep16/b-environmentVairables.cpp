#include <iostream>
// a C-String: VarName=Value 
using namespace std;
int main(int argc, char* argv[], char* env[]) {
   cout << "03-sep16 OOP345 NRA" << endl;
   cout << endl << "Command line argurmets: " << endl;
   for (int i = 0; i < argc; i++) {
      cout << (i + 1) << ": " << argv[i] << endl;
   }
   cout << endl << "OS Environment variables: " << endl;
   for (int i = 0; env[i] ; i++) {
      cout << (i + 1) << ": " << env[i] << endl;
   }

   return 0;
}