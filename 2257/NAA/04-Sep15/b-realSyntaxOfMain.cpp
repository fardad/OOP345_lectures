#include <iostream>
using namespace std;

// OSVariable=OSValue
int main(int argc, char* argv[], char* env[]) {
   cout << "04-Sep15 OOP345NAA" << endl;
   cout << "Command line arguments: " << endl;
   for (int i = 0; i < argc; i++) {
      cout << (i + 1) << ": " << argv[i] << endl;
   }
   cout << endl << "OS, environment variables: " << endl;
   for (int i = 0; env[i]; i++) {
      cout << (i + 1) << ": " << env[i] << endl;
   }
   return 0;
}