#include <iostream>
using namespace std;

void setToppp(const char*** des, const char* src) {
   **des = src;
}

bool search(const char* src, const char** ptr, char ch) {
   bool found = false;
   while (!found && *src) {
      if (*src == ch) {
         //*ptr = src;
         setToppp(&ptr, src);
         found = true;
      }
      src++;
   }
   return found;
}

//void setTo10(int* a) {
//   a = 10;
//}

int main() {
  /* int x = 1111;
   setTo10(&x);
   cout << x << endl;*/

   char src[] = "Fred000000";
   const char* chptr = nullptr;
   if (search(src, &chptr, 'e')) {
      cout << chptr << endl;
   }
   else {
      cout << "not found!" << endl;
   }
   return 0;
}