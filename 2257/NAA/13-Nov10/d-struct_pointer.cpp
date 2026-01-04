#include <iostream>
#include <string>
using namespace std;

struct Course {
   string title;
   double grade;
};

int main() {
   int numCourses;
   cout << "Enter number of courses: ";
   cin >> numCourses;
   cin.ignore();  // Clear newline

   Course* courses = new Course[numCourses];  // Dynamic array of structs

   double totalGrade = 0.0;
   for (int i = 0; i < numCourses; ++i) {
      cout << "Enter title for course " << (i + 1) << ": ";
      getline(cin, courses[i].title);
      cout << "Enter grade: ";
      cin >> courses[i].grade;
      cin.ignore();  // Clear newline
      totalGrade += courses[i].grade;
   }

   // Aggregate via pointer
   Course* ptr = courses;
   cout << "Course summary:" << endl;
   for (int i = 0; i < numCourses; ++i) {
      cout << ptr->title << ": " << ptr->grade << endl;  // Arrow operator
      ++ptr;
   }
   cout << "Average grade: " << (totalGrade / numCourses) << endl;

   delete[] courses;
   courses = nullptr;

   return 0;
}