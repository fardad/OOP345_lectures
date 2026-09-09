#include <iostream>
using namespace std;
struct Point {
    double x;
    double y;
    char a;
};
int main() {
    cout << alignof(int) << endl;
    cout << alignof(double) << endl;


    cout << sizeof(Point) << endl;
    cout << alignof(Point) << endl;
    return 0;
}