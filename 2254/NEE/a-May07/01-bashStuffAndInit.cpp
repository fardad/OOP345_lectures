/*
.bash_profiles aliases to set for c++ 17 and valgrind
Add the following to your .bash_profile
alias G++="/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g "
alias g++17="/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 "
alias vg="valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes"
*/

#include <iostream>
using namespace std;
int main( ) {
   cout << "OOP345 NEE May 07" << endl;
   return 123;// is returned to the OS
}

