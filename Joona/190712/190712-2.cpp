/*
	메인함수가 정상적으로 실행되도록 클래스의 정의를 수정하세요
	출력결과
	1
	1
	* 단, a는 정적 멤버, b는 비정적 멤버임은 유지할 것
	*/
#include <iostream>
using namespace std;
class StaticTest {
	static int a;
	int b;
public:
	StaticTest() {
		b = 1;
	}
	static int getA() {
		return a;
	}
	int getB() {
		return b;
	}
};

int StaticTest::a = 1;

int main() {
	cout << StaticTest::getA() <<endl;
	StaticTest test;

	cout << test.getB() << endl;
}
