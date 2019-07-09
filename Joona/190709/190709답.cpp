#include <iostream>
using namespace std;

class Plus {
	int a, b, sum;

public:
	Plus() : a(0), b(0), sum(0) { cout << "생성되었습니다" << endl; }

	Plus(int _a) : Plus() { a = _a; }

	Plus(int _a, int _b) : Plus(_a) { b = _b; }

	~Plus() {
		sum = a + b;
		cout << "sum : " << sum << endl;
		cout << "소멸되었습니다" << endl;
	}
};

int main() {
	int x, y;
	cin >> x >> y;

	Plus p(x, y);
	//Plus p2 = Plus(x, y);
	//Plus p3 = { x, y };
	//Plus p4 = Plus{ x, y };
	//Plus p5{ x, y };

	return 0;
}