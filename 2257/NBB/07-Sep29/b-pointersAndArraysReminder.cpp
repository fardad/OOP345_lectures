#include <iostream>
using namespace std;
void sum(int a, int b) {
   cout << (a + b) << endl;
}
void prod(int a, int b) {
   cout << (a * b) << endl;
}
void foo(int* p) {
   cout << p[2] << endl;
}
int main() {
   cout << "07-Sep29 OOP345 NBB" << endl;
   int a[5]{ 100, 200, 300, 400, 500 };
   int* p = a;
   cout << reinterpret_cast<unsigned long long>(a) << endl;
   cout << reinterpret_cast<unsigned long long>(sum) << endl;
   cout << reinterpret_cast<unsigned long long>(prod) << endl;
   sum(10, 20);
   foo(a);
   return 0;
}
