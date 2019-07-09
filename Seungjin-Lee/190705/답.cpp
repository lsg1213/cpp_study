#include <iostream>
using namespace std;
class rect {
	int x, y;

public:
	void set() {
		
		while (true) {
			cout << "x값을 입력하시오(0~100)" << endl;
			cin >> x;
			if (x < 0 || x > 100) {
				cout << "잘못입력했습니다" << endl;
				continue;
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
			break;
		}
		while (true) {
			cout << "y값을 입력하시오(0~100)" << endl;
			cin >> y;
			if (y < 0 || y > 100) {
				cout << "잘못입력했습니다" << endl;
				continue;
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
			break;
		}
	}

	void printing() {
		cout << "직사각형의 넓이는 " << x * y << "입니다." << endl;
	}


};

int main() {
	rect rect;
	rect.set();
	rect.printing();
}