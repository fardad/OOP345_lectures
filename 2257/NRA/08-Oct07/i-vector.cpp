// vector_demo.cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<string> students = { "Amy", "Bob", "Clara" };
   students.push_back("Daniel");

   cout << "Students: ";
   for (auto& s : students)
      cout << s << " ";
   cout << endl;

   cout << "Total: " << students.size() << endl;

   students.insert(students.begin() + 1, "Eve");
   students.erase(students.begin() + 3);
   students.pop_back();
   cout << "Updated list: ";
   for (auto s : students) cout << s << " ";
   cout << endl;
   for (size_t i = 0; i < students.size(); i++) {
      cout << students[i] << endl;
   }
   return 0;
}