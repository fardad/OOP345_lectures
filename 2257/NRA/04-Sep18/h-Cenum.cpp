// plain_enum.cpp
#include <iostream>
#include <string>
using namespace std;

enum Colour { white, red, green, blue };

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
   Colour wall = red, ceiling = white, door = green;
   cout << wall << " " << ceiling << " " << door << endl;
   return 0;
}