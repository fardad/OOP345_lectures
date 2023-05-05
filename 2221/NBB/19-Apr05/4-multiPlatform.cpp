#include <iostream>
using namespace std;
// macro
#ifdef max
#undef max
#endif // max
#define max(x, y) ((x)>(y)?(x):(y)) 

#define LINUX 1
#define WIN 2

#define OS LINUX


void clrscreen() {
#if OS == WIN
   system("cls");
#elif OS == LINUX
   system("clear");
#else
   cout << "OS not supported!!!" << endl;
#endif
}

int main() {
   clrscreen();
   return 0;
}


