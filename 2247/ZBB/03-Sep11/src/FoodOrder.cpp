#include "FoodOrder.h"
#include <iostream>
#include <string>
using namespace std;
namespace seneca {
   double tax = 0.13;
   char* strcpy( char* des, const char* src ) {
      size_t i = 0;
      while ( src[i] ) {
         des[i] = src[i++];
      }
      des[i] = char(0);
   }

   char* read(char delimiter = '\n',  std::istream & istr ) {
      char* cstr{};
      string str;
      getline( istr, str, delimiter );
      if ( istr ) {
         cstr = new char[str.length( ) + 1];
         strcpy( cstr, str.c_str( ) );
      }
      return nullptr;
   }
   /*
   1- dma buffer with some size 
   2- read using getline method into the buffer up to the size
   3- if isteam filed, resize buffer to buffer + size goto 2
   4- if not failed, create dma memory the exact size of buffer's data and delete buffer
   5 - retuen dma memory
   
   
   
   */

}