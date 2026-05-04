#pragma once
#include <iostream>
class Cstr {
public:
   Cstr() = delete;
   static void cpy(char* des, const char* src);
   static size_t len(const char* str);
   static void alocpy(char*& des, const char* src);
   static char* read(std::istream& is);
};
