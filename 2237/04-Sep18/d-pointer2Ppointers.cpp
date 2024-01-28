#include <iostream>
using namespace std;

void prnAddress(int* ptr) {
   cout << unsigned(ptr) << endl;

}

void yetGotoNextOneLevelHigher(int*** ptr) {
   (**ptr)++;
}

void gotoNextElement(int** ptr) { //integer-pointer, pointer ptr
   yetGotoNextOneLevelHigher(&ptr);
   prnAddress(*ptr);
}

void gotoNextElement(int*& ref) { //integer-pointer, reference ref
   ref++;
   prnAddress(ref);
}

void gotoNextNumber(long* num) {
   (*num)++;
}

int main() {
   int ar[5]{ 10,20,30,40,50 };
   int* p = ar;
   //long n = 30;
   //gotoNextNumber(&n);
   //cout << n << endl;


   prnAddress(p);
   cout << "*p: " << *p << endl;
   p++;
   prnAddress(p);
   cout << "*p: " << *p << endl;
   gotoNextElement(&p);
   prnAddress(p);
   cout << "*p: " << *p << endl;
   gotoNextElement(p);
   prnAddress(p);
   cout << "*p: " << *p << endl;
   return 0;
}