#include <iostream>
using namespace std;


int n;
void set() {
	n = 10;
}

namespace doodle {
	void set() {
		n = 20;
	}
	int n;

	namespace google {
		int n;
		void set() {
			n = 30;
		}
	}
}


int main() {
	::set();
	doodle::set();
	doodle::google::set();
	cout << ::n << endl;
	cout << doodle::n << endl;
	cout << doodle::google::n << endl;
}
