#include <iostream>
#include <string>
using namespace std;

enum WeekDay{sun=20, mon, tue, wed, thu, fri, sat };
enum class Direction { North, South, East, West };

typedef enum { // in C we used to do this
   False, True
} boolean;

int main( ) {
   WeekDay w;
   w = thu;
   Direction D;
   D = Direction::West;
   return 0;
}