#include <iostream>
using namespace std;

bool search(const char* src, const char*& ptr, char ch) {
   bool found = false;
   while (!found && *src) {
      if (*src == ch) {
         ptr = src;
         found = true;
      }
      src++;
   }
   return found;
}

int main() {
   char src[] = "Fred000000";
   const char* chptr = nullptr;
   if (search(src, chptr, 'e')) {
      cout << chptr << endl;
   }
   else {
      cout << "not found!" << endl;
   }
   return 0;
}