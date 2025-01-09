// lecture video at: https://youtu.be/N_baE60Yu-o

#include <iostream>
using namespace std;
void foo( int (*p)[3][3][4][5][6] ) {

}
int main( ) {
   int a[2][3][3][4][5][6];
   foo( a );
   return 0;
}