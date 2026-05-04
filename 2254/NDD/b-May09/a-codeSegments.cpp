#include <iostream>
using namespace std;
int globalVar = 10; // Global   data segment (initialized)

int globalUninit;   // BSS segment 

void foo() {
   int localVar = 5;    // stack

   int* heapVar= new int(500); // heap


   std::cout << "Code segment: address of foo = " << reinterpret_cast<unsigned long long>(foo) << '\n';
   std::cout << "Data segment: address of globalVar = " << reinterpret_cast<unsigned long long>(&globalVar) << '\n';
   std::cout << "BSS segment: address of globalUninit = " << reinterpret_cast<unsigned long long>(&globalUninit) << '\n';
   std::cout << "Stack: address of localVar = " << reinterpret_cast<unsigned long long>(&localVar) << '\n';
   std::cout << "Heap: address of heapVar = " << reinterpret_cast<unsigned long long>(heapVar) << '\n';

   delete heapVar;
}


int main() {
   cout << "OOP345 NDD May09" << endl;
   int A[50];
   cout << reinterpret_cast<unsigned long long>(&A[0]) << endl;
   cout << reinterpret_cast<unsigned long long>(A) << endl;
   foo();
   return 0;
}