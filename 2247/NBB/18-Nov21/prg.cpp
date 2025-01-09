#include <iostream>
using namespace std;
int main( ) {
   int* p = reinterpret_cast<int*>(16u);
   int ( *q )[3] = reinterpret_cast<int( * )[3]>(16u);
   int ( *r )[3][2] = reinterpret_cast<int( * )[3][2]>(16u);
   cout << reinterpret_cast<unsigned>(p) << endl;
   cout << reinterpret_cast<unsigned>(q) << endl;
   cout << reinterpret_cast<unsigned>(r) << endl;
   p++;
   q++;
   r++;
   cout << reinterpret_cast<unsigned>(p) << endl;
   cout << reinterpret_cast<unsigned>(q) << endl;
   cout << reinterpret_cast<unsigned>(r) << endl;
   int a[4] = { 1, 2, 3, 4 };
   int b[2][3] = {
      {10, 20, 30 },
      {40, 50, 60 }
   };
   int c[100][3][2]{};
   cout << reinterpret_cast<unsigned>(a) << endl;
   cout << reinterpret_cast<unsigned>(a + 1) << endl;
   cout << reinterpret_cast<unsigned>(b) << endl;
   cout << reinterpret_cast<unsigned>(b + 1) << endl;
   cout << reinterpret_cast<unsigned>(c) << endl;
   cout << reinterpret_cast<unsigned>(c + 1) << endl;
   cout << reinterpret_cast<unsigned>(c[0]) << endl;
   cout << reinterpret_cast<unsigned>(c[0] + 1) << endl;
   cout << reinterpret_cast<unsigned>(c[0][0]) << endl;
   cout << reinterpret_cast<unsigned>(c[0][0] + 1) << endl;
   // the name of 100 people with first, middle and last name with max of 20 char for names. 

   char name[100][3][20];
   int ints[100][3][20];
   cout << sizeof( name ) << endl;
   cout << sizeof( ints ) << endl;


   return 0;
}