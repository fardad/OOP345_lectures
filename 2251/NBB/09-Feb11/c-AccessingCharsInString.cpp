#include <iostream>
#include <string>
using namespace std;
int main( ) {
   string str1 = "OOP345NBB 09-Feb11";
   cout << str1 << endl;
   string word = "Apple";
   cout << word[0] << endl;       // Output: A
   word[0] = 'a';                 // Modify the first character
   cout << word << endl;          // Output: apple
   cout << word.at( 2 ) << endl;    // Output: p (safe access, checks bounds)
   return 0;
}