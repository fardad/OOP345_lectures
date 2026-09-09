#include <iostream>
using namespace std;

class Counter {
    static int count;
    size_t m_cnt{};
public:
    Counter() { ++count; }
    ~Counter() { --count; }
    void click() { m_cnt++; }
    static int getCount() { return count; }
};
int Counter::count = 0;

int main() {
    cout << Counter::getCount() << endl;
    Counter C[5];
    Counter *p = new Counter[3];
    cout << C[3].getCount() << endl;
    cout << p->getCount() << endl;
    delete[] p;
    cout << C[0].getCount() << endl;
    return 0;
}