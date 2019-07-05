declare int n to print 20 0 30

 #include <iostream>

using namespace std;
void set() {
	n = 10;
}

namespace doodle {
	void set() {
		n = 20;
	}
	namespace google {
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