#include <iostream>

using namespace std;
// 복소수의 덧셈, 곱셈, 나눗셈, 뺄셈 구현( 1~3번 문제 )
class Complex {
	double real;
	double imag;
public:
	// 1. 한 줄에 생성자 구현(입력 수정x)
	Complex(double real = 0, double imag = 0) : real(real), imag(imag) { }

	double GetReal() {
		return real;
	}
	double GetImag() {
		return imag;
	}

	// 2. switch문을 이용하여 사칙연산 구현
	// 0으로 나누는 경우는 입력으로 없다.(main 함수에서 걸러서 들어옴)
	void calculate(double _real, double _imag, char oper) {
		double real_result, imag_result;
		switch (oper) {
		case '+':
			real += _real;
			imag += _imag;
			break;
		case '-':
			real -= _real;
			imag -= _imag;
			break;
		case '*':
			real_result = real * _real - imag * _imag;
			imag_result = real * _imag + imag * _real;
			real = real_result;
			imag = imag_result;
			break;
		case '/':
			real_result = (real*_real + imag * _imag) / (_real*_real + _imag * _imag);
			imag_result = (-real * _imag + imag * _real) / (_real*_real + _imag * _imag);
			real = real_result;
			imag = imag_result;
			break;
		}
	}
	// 3. "All is over"을 출력하는 소멸자 구현
	~Complex() {
		cout << "All is over" << endl;
	}
};

int main() {

	while (true) {
		cout << "-----------------------------------------------------" << endl;
		cout << "Calculator is operating" << endl;
		cout << "Please put first complex number REAL part" << endl;
		double first_real;
		cin >> first_real;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Something wrong in your input" << endl;
			cin >> first_real;
		}
		cout << "Please put first complex number IMAGINARY part" << endl;
		double first_imag;
		cin >> first_imag;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Something wrong in your input" << endl;
			cin >> first_imag;
		}
		Complex comp(first_real, first_imag);
		cout << "Your first complex number is :" << comp.GetReal() << "+i(" << comp.GetImag() << ")" << endl;
	next:
		char oper;
		cout << "Please put operator(+, -, *, /)" << endl;
		cin >> oper;
		while (cin.fail() || !(oper == '+' || oper == '-' || oper == '*' || oper == '/')) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Something wrong in your input" << endl;
			cin >> oper;
		}
		cout << "You choose " << oper << endl;
		cout << "Please put next complex number REAL part" << endl;
		double next_real;
		cin >> next_real;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Something wrong in your input" << endl;
			cin >> next_real;
		}
		cout << "Please put next complex number IMAGINARY part" << endl;
		double next_imag;
		cin >> next_imag;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Something wrong in your input" << endl;
			cin >> next_imag;
		}
		if (oper == '/' && next_real == 0 && next_imag == 0) {
			cout << "ERROR : You can't divide number by 0" << endl;
			cout << "Reboot the calculator" << endl;
			continue;
		}
		comp.calculate(next_real, next_imag, oper);
		cout << "Your next complex number is :" << next_real << "+i(" << next_imag << ")" << endl;
		cout << "The result is" << endl;
		if (!(comp.GetReal() || comp.GetImag())) { cout << '0'; }
		if (comp.GetReal()) { cout << comp.GetReal(); }
		if (comp.GetImag()) { cout << "+i(" << comp.GetImag() << ")"; }
		cout << endl;
		int menu;
		cout << "Calculate continuous(1)? or reset number(2)? or exit(3)? Put number 1, 2, or 3" << endl;
		cin >> menu;
		while (cin.fail() || !(menu == 1 || menu == 2 || menu == 3)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Something wrong in your input" << endl;
			cin >> menu;
		}
		cout << "You choose ";
		if (menu == 1) {
			cout << "continuous calculating" << endl << endl;
			goto next;
		}
		else if (menu == 2) {
			cout << "reset number" << endl;
			continue;
		}
		else {
			cout << "exit the calculator.\n" << "Good Bye!" << endl;
			break;
		}
	}
	return 0;
}