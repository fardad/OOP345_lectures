#include <iostream>
using namespace std;

/* practice
Write the follwing program:

showenv <Enviroment Variable name><ENTER>

- Displays the value of the Envroment variable and sets the execution status to 0
or proper error message or it is not found seting the execution status to -1;
- Also it checks to make sure the name of the exe program is showenv

*/


int main(int argc, char* argv[], char* env[]) {
    cout << "OOP345 NAA May05" << endl;
    for (int i = 0; i < argc; i++) {
        cout << (i + 1) << "> " << argv[i] << endl;
    }
    cout << "Environment variables...." << endl;
    for (int i = 0; env[i]; i++) {
        cout << (i + 1) << "> " << env[i] << endl;
    }
    return 123;
}