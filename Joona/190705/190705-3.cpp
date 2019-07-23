#include <iostream>
using namespace std;

class Rectangle {
	int w, h;

public:
	void setWidth(int _w) {
			w = _w;
	}

	void setHeight(int _h) {
			h = _h;
	}

	void printSpace(){
		cout << "직사각형의 면적은 " << w * h << "입니다." << endl;
	}
};


int main() {
	bool check = false;
	int x, y;
	Rectangle r;
	
	while (!check) {
		cout << "width (0 이상 100 이하): ";
		cin >> x;
		cout << "height(0 이상 100 이하): ";
		cin >> y;

		if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
			check = true;
		else
			cout << "잘못입력하셨습니다." << endl;
	}

	r.setWidth(x);
	r.setHeight(y);
	r.printSpace();

}