#include <iostream>
using namespace std;
class Base {
public :
	int bA;
protected:
	int bB;
private:
	int bC;
};
/*1. Derived클래스와 Dderived 클래스에서 참조가능한 변수는? 그 이유는? */
class Derived : private Base {
public:
	int dA;
	void dFunc() {
		//bA = 10;
		//bB = 20;
		//bC = 30; //X
		//dA = 10;
		//dB = 20;
		//dC = 30;
	}
protected:
	int dB;
private:
	int dC;
};

class Dderived : public Derived {
public:
	int ddA;
	void ddFunc() {
		//bA = 1; //X
		//bB = 2; //X
		//bC = 3; //X
		//dA = 1;
		//dB = 2;
		//dC = 3; //X
		//ddA = 1;
		//ddB = 2;
	}
private:
	int ddB;
};

int main() {
	Base x;
	Derived y;
	Dderived z;

	/*2. 출력 결과를 예상해보시오*/
	x.bA = 5;
	y.dA = 10;
	z.ddA = 15;
	int* p = &x.bA;
	int* pp = &y.dA;
	int* ppp = &z.ddA;
	int& r = *p;
	int* (&rp) = pp;
	int** rpp = &ppp;

	r = *pp / *p;
	*rp = 20;
	rp = ppp;
	*pp = 10;
	rp = &z.ddA;
	*rpp = &y.dA;
	p = &y.dA;
	*p = r*2;

	cout << x.bA << endl;
	cout << y.dA << endl;
	cout << z.ddA << endl;
	cout << *p << endl;
	cout << *pp << endl;
	cout << *ppp << endl;
	cout << r << endl;
	cout << *rp << endl;
	cout << **rpp << endl;

	//2 4 10 4 10 4 2 10 4

	return 0;
}