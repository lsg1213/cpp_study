#include <iostream>

using namespace std;
// º¹¼Ò¼öÀÇ µ¡¼À, °ö¼À, ³ª´°¼À, »¬¼À ±¸Çö
class Complex {
	double real;
	double imag;
public:
	Complex(double real = 0, double imag = 0) : real(real), imag(imag) {	}

	double GetReal() {
		return real;
	}
	double GetImag() {
		return imag;
	}

	void calculate(double _real, double _imag, char oper) {
		double tmp_real = real;
		double tmp_imag = imag;
		switch (oper)
		{
		case '+':
			real += _real;
			imag += _imag;
			break;
		case '-':
			real -= _real;
			imag -= _imag;
			break;
		case '*':
			real = real * _real - imag * _imag;
			imag = tmp_real * _imag + imag * _real;
			break;

		default:
			if (_real == 0) {
				real = imag / _imag;
				imag = -(real / imag);
			}
			else if (_imag == 0) {
				real /= _real;
				imag /= _real;
			}
			else {
				calculate(_real, -_imag, '*');
				calculate(tmp_real*tmp_real + tmp_imag * tmp_imag, 0, '/');
			}
			break;
		}
	}

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
