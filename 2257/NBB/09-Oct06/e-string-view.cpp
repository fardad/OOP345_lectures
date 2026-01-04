// string_view_example.cpp
#include <iostream>
#include <string>
#include <string_view>
using namespace std;

void display(string_view sv) {
   cout << "View: [" << sv << "], length = " << sv.size() << endl;
}

int main() {
   string full = "Hello from Seneca!";
   string_view part(full.c_str() + 6, 4); // "from"
   display(part);

   string_view tail = full.substr(11); // "Seneca!"
   display(tail);

   // Searching
   size_t pos = full.find("Seneca");
   if (pos != string::npos)
      cout << "'Seneca' starts at index " << pos << endl;

   return 0;
}