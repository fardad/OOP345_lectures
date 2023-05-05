#include <iostream>
using namespace std;
class Container {
	int m_data;
	static int m_cnt;
public:
	Container(int data = 1) {
		m_data = data;
		m_cnt++;
	}
	ostream& display(ostream& ostr= cout) {
		ostr << m_data << " (" << m_cnt << ")" << endl;
		return ostr;
	}
	~Container() {
		m_cnt--;
	}
};
int Container::m_cnt = 0;

int main() {
	Container C[3]={10, 20, 30};
	C[0].display();
	Container* p;
	p = new Container(40);
	p->display();
	delete p;
	C[1].display();
   return 0;
}

