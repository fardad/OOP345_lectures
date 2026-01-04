// scoped_enum.cpp
#include <iostream>
#include <string>
using namespace std;

enum class Colour { white, red, green, blue };

ostream& operator<<(ostream& os, const Colour& colour) {
   switch (colour) {
   case Colour::white: os << "white"; break;
   case Colour::red:   os << "red";   break;
   case Colour::green: os << "green"; break;
   case Colour::blue:  os << "blue";  break;
   default: os << "none";
   }
   return os;
}

int main() {
   Colour wall = Colour::red, ceiling = Colour::white, door = Colour::green;
   cout << wall << " " << ceiling << " " << door << endl;
   return 0;
}