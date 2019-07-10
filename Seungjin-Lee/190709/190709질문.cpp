#include <iostream>
using namespace std;

class Plus {
	int a, b, sum;

public:
	//1. 생성자 채우기
	Plus() : a(0), b(0), sum(0) { cout << "생성되었습니다" << endl; }

	Plus(int _a) : Plus() { 
		a = _a;
	 }

	Plus(int _a, int _b) : Plus(_a) { 
		b = _b;
	 }

	//2. 소멸자에서 sum 출력하고 "소멸되었습니다" 출력
	~Plus() {
		cout << sum << endl;
		cout << "소멸되었습니다" << endl;
	}

};


int main() {
	int x, y;
	cin >> x >> y;

	//3. 같은 표현 생각해보기
	Plus p1 = (x,y);
	Plus p2 = {x,y};
	Plus p3{x,y};
	Plus p4(x, y);

	
	return 0;
}