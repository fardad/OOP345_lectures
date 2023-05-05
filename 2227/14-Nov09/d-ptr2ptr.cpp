#include <iostream>
using namespace std;
//void setToTen(int* val) {
//   *val = 10;
//}
//int main() {
//   int i{};
//   setToTen(&i);
//   cout << i << endl;
//   return 0;
//}

void setPtr(const char*** p, const char* src) {
   **p = src;
}

bool search(const char* src, const char** ptr, char ch) {
   bool found = false;
   while(!found && *src) {
      if(*src == ch) {
         *ptr = src;
         setPtr(&ptr, src);
         found = true;
      }
      src++;
   }
   return found;
}
int main() {
   char str[50] = "Fredrick";
   const char* chptr{};
   if(search(str, &chptr, 'e')) {
      cout << chptr << endl;
   }
   else {
      cout << "not found!" << endl;
   }
   return 0;
}
