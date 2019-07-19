#include <iostream>
using namespace std;
/* 1. const 붙일수 있는 곳에 다 붙여보기 */
class Op {
public:
	/* 2. 생성자의 선언과 정의 분리하기(밑에 내용과 동일한 결과 나오게 수정) */
	Op();
	Op(int a, int b, int c);


	float getA();
	float getB();
	float getC();

	/* 3. 덧셈, 뺄셈은 a끼리, b끼리, c끼리 연산.
	곱셈, 나눗셈은 a, b, c에 입력된 숫자가 각각 연산.
	멤버 메서드의 선언, 정의 분리해서 클래스 밖에서 정의하기*/
	Op operator+(Op);
	Op operator-(Op);
	Op operator*(const float);
	Op operator/(const float);


	static Op Sum(Op x, Op y) {
		return Op(x.a + y.a, x.b + y.b, x.c + y.c);
	}


private:
	int a;
	int b;
	int c;
};

Op::Op() :a(0), b(0), c(0) { }
Op::Op(int a, int b, int c) : a(a), b(b), c(c) { }

float Op::getA(){ return a; }
float Op::getB(){ return b; }
float Op::getC(){ return c; }

int main() {
	Op x(3,6,9), y(2,4,6);
	Op z1 = x + y;
	Op z2 = x - y;
	Op z3 = x * 5;
	Op z4 = y / 2;
	/* 4. 정적 메서드 사용하여 z1과 동일한 결과나오는지 확인*/
	Op z5 = Op::Sum(x,y);

	cout << z1.getA() << ", " << z1.getB() << ", " << z1.getC() << endl;
	cout << z2.getA() << ", " << z2.getB() << ", " << z2.getC() << endl;
	cout << z3.getA() << ", " << z3.getB() << ", " << z3.getC() << endl;
	cout << z4.getA() << ", " << z4.getB() << ", " << z4.getC() << endl;
	cout << z5.getA() << ", " << z5.getB() << ", " << z5.getC() << endl;

	return 0;
}

Op Op::operator+(Op x){
	return Op(a+x.getA(), b+x.getB(), c+x.getC());
}

Op Op::operator-(Op x){
	return Op(a-x.getA(), b-x.getB(), c-x.getC());
}

Op Op::operator*(const float x){
	return Op(a*x, b*x, c*x);
}

Op Op::operator/(const float x){
	return Op(a/x, b/x, c/x);
}
