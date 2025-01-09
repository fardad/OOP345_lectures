#pragma once
#include <iostream>
class Cstr {
public:
   Cstr() = delete;
   static void cpy( char* des, const char* src );
//   static void cpy( char* des, const char* src, size_t len );
   static size_t len(const char* str);
//   static int cmp( const char* left, const char* right );
   static void alocpy(char*& des, const char* src);
   static char* read(std::istream& is);
};
