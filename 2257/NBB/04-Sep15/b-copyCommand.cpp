#include <iostream>
#include <fstream>
using namespace std;
// copy sourcefile destfile<ENTER>
int main(int argc, char* argv[]) {
   if (argc != 3) {
      cout << "Help: copy <source file> <dest file> <ENTER>" << endl;
   }
   else {
      ifstream infile(argv[1]);
      if (!infile) {
         cout << "can not open " << argv[1] << endl;
      }
      else {
         ofstream outfile(argv[2]);
         if (!outfile) {
            cout << "error for out!" << endl;
         }
         else {
            char ch;
            while (infile.get(ch)) {
               outfile.put(ch);
            }
         }
      }
   }
   return 0;
}