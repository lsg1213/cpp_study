#include <iostream>
#include <string>
using namespace std;
/*
	다음 코드는 2 x 2 행렬 계산기이다.
    총 문제는 2문제 main 함수 건들지 말 것.
*/
class matrix {
	double **num;
	string name;
public:
	void showMatrix() const;
	matrix(string);
	matrix(string, double, double, double, double);
	matrix getMatrix(string name) const;
	void change(double, double, double, double);
    /*
        1. 아래 오퍼레이터를 완성하라. 선언 변경 금지. main 함수 참고할 것.
        void operator+(matrix rhs);
        void operator-(matrix rhs);
        void operator*(matrix rhs);
    */
};

class matrix2 {
	double **num;
	string name;
public:
	void showMatrix() const;
	matrix2(string);
	matrix2(string, double, double, double, double);
	void change(double, double, double, double);
    /*
        2. 아래 오퍼레이터 연산 메서드를 상수화하여 완성하라. 선언 부분도 변경 필요.
        내적은 계산이 복잡하여 주어졌다.

        matrix2 operator+(matrix2 rhs) ;
        matrix2 operator-(matrix2 rhs) ;
        matrix2 operator*(matrix2 rhs) ;
    */

	void change(string);
};
matrix2 matrix2::operator*(matrix2 rhs) {
	// 아래 데이터는 계산 값
	//"", num[0][0] * rhs.num[0][0] + num[0][1] * rhs.num[1][0], num[0][0] * rhs.num[0][1] + num[0][1] * rhs.num[1][1],
	//	num[1][0] * rhs.num[0][0] + num[1][1] * rhs.num[1][0], num[1][0] * rhs.num[0][1] + num[1][1] * rhs.num[1][1]
}

matrix2::matrix2(string name) : name(name){
	num = new(double*[2]);
	num[0] = new(double[2]);
	num[1] = new(double[2]);
	change(0, 0, 0, 0);
}
matrix2::matrix2(string name, double a, double b, double c, double d) : matrix2(name) {
	change(a, b, c, d);
}
void matrix2::showMatrix() const {
	cout << name << " is the following matrix" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << num[i][j] << ' ';
		}
		cout << endl;
	}
}


void matrix::change(double a, double b, double c, double d) {
	num[0][0] = a;
	num[0][1] = b;
	num[1][0] = c;
	num[1][1] = d;
}
void matrix2::change(double a, double b, double c, double d) {
	num[0][0] = a;
	num[0][1] = b;
	num[1][0] = c;
	num[1][1] = d;
}
void matrix2::change(string _name) {
	name = _name;
}
matrix::matrix(string name) : name(name) {
	num = new(double*[2]);
	num[0] = new(double[2]);
	num[1] = new(double[2]);
	change(0, 0, 0, 0);
}
matrix::matrix(string name, double a, double b, double c, double d) : matrix(name) {
	change(a, b, c, d);
}
void matrix::showMatrix() const {
	cout << name << " is the following matrix" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << num[i][j] << ' ';
		}
		cout << endl;
	}
}
matrix matrix::getMatrix(string name) const {
	return matrix(name, num[0][0], num[0][1], num[1][0], num[1][1]);
}
int main() {
    // 문제 1 참고
	matrix a("a", 1, 1, 1, 1), b("b", 2, 2, 2, 2);
	a + b;
	a.showMatrix();
	a.change(1, 1, 1, 1);
	a - b;
	a.showMatrix();
	a.change(1, 1, 1, 1);
	a * b;
	a.showMatrix();
    //참고 끝
	matrix2 c("c", 1, 1, 1, 1), d("d", 2, 2, 2, 2);
	{
		matrix2 e = c + d;
		e.change("c + d");
		e.showMatrix();
	}
	{
		matrix2 e = c - d;
		e.change("c - d");
		e.showMatrix();
	}
	{
		matrix2 e = c * d;
		e.change("c * d");
		e.showMatrix();
	}
	return 0;
}