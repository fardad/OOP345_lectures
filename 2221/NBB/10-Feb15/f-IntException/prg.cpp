#include <iostream>
using namespace std;
#include "Validation.h"
#include "Int.h"

int main() {
   bool ok = false;
   int tries = 0;
   ValidAge va;
   ValidMark vm;
   Int age(va);
   Int mark(vm);
   do {
      try {
         cout << "Enter your age: ";
         cin >> age;  // any statement that throws an exception must be in a try statement.
         ok = true;
      }
      catch (tooYoungExp e) {
         cout << e.what() << ", try again" << endl;
      }
      catch (tooOldExp e) {
         cout << e.what() << ", try again" << endl;
      }
      catch (badIntExp e) {
         cin.clear();
         cout << e.what() << ", try again" << endl;
      }
      catch (exception e) {
         cout << e.what() << endl;
         cout << "critical error, terminating program" << endl;
         exit(-1);
      }
      catch (...) {
         cout << "Unknown exception!" << endl;
         exit(-1);
      }
      cin.ignore(1000, '\n');
   } while (!ok);
   cout << age << " years old? cool!, what would you like to drink?" << endl;
   ok = false;
   do {
      try {
         cout << "Enter the mark: ";
         cin >> mark;
         ok = true;
      }
      catch (badMark e) {
         cout << e.what() << ", try again" << endl;
      }
      catch (badIntExp e) {
         cin.clear();
         cout << e.what() << ", try again" << endl;
      }
      catch (exception e) {
         cout << e.what() << endl;
         cout << "critical error, terminating program" << endl;
         exit(-1);
      }
      cin.ignore(1000, '\n');
   } while (!ok);
   cout << "The mark is " << mark << endl;

   return 0;
}