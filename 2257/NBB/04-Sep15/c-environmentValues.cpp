#include <iostream>
using namespace std;

// OSVariable=OS_value

int main(int argc, char* argv[], char* env[]) {
   cout << "04Sep15 OOP345NAA" << endl;
   cout << argc << " command argurmets: " << endl;
   for (int i = 0; i < argc; i++) {
      cout << (i + 1) << ": " << argv[i] << endl;
   }
   cout << endl << "Environment Variables:" << endl;
   for (int i = 0; env[i] ; i++) {
      cout << (i + 1) << ": " << env[i] << endl;
   }

   return 0;
}