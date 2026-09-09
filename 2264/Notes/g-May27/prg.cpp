#include <iostream>
#include <string>
using namespace std;
bool isAdult(int num, string& errorMes) {
    errorMes = "No children or senios allowed!";
    return num >= 18 && num <= 65;
}
bool validNoOfStudents(int num, string& errorMes) {
    errorMes = "values between 10 and 35 please!";
    return num >= 10 && num <= 35;
}
int getInt(bool (*isValid)(int, string&) = nullptr);


auto main() -> int {
    cout << "Enter your age:\n> ";
    int age = getInt(isAdult);
    cout << "age: " << age << endl;
    cout << "Enter number of students:\n> ";
    int nos = getInt(validNoOfStudents);
    cout << "Number of students: " << nos << endl;
    return 0;
}
int getInt(bool (*isValid)(int, string&)) {
    int num{};
    bool done = false;
    string errmes{};
    do {
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cout << "Invlid integer, try again...\n> ";
        }
        else {
            if (cin.peek() != '\n') {
                cout << "Only an integer number please...\n> ";
            }
            else if (isValid == nullptr || isValid(num, errmes)) {
                done = true;
            }
            else {
                cout << errmes << "\n> ";
            }
        }
        cin.ignore(10000, '\n');
    } while (!done);
    return num;
}
