
#include <iostream>
#include <utility>
using namespace std;
enum Colour { white, red=10, green, blue };
enum Boolean {False, True};
ostream& operator<<(ostream& os, const Colour& colour) {
   switch (colour) {
   case white: os << "white"; break;
   case red:   os << "red";   break;
   case green: os << "green"; break;
   case blue:  os << "blue";  break;
   default:    os << "none";
   }
   return os;
}

int main() {
   cout << white << endl;
   Colour c;
   c = red;
   //c = 3; allowed in C but not C++;
   Colour wall = red, ceiling = white, door = green;
   cout << wall << " " << ceiling << " " << door << endl;
   return 0;

}