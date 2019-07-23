#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Student {
public:
	Student() : id(0), name(NULL) {
		cout << "Student() 생성자" << endl;
	}

	Student(int _id, const char* _name) {
		cout << "Student(int, char*) 생성자" << endl;
		id = _id;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	/*1. 복사생성자 오버로딩 만들기
	얕은 복사가 아니라 깊은 복사가 될 수 있도록*/
	Student(Student& rhs) {
		cout << "Student(Student&) 복사생성자" << endl;
		//code
	}

	/*2. 대입 연산자 오버로딩 만들기
	c.operator=(c) 처럼 자기자신을 대입할 때 문제없이 작동하도록 if구문 이용*/
	Student& operator=(const Student& rhs) {
		//code
	}

	~Student() {
		cout << "~Student() 소멸자" << endl;
		delete[] name;
		name = NULL;
	}

	int getID() {
		return id;
	}

	char* getName() {
		return name;
	}

private:
	int id;
	char* name;
};

int main() {
	Student a(123456, "abc");
	Student b(a);
	Student c;
	c = a;
	c.operator=(c);

	cout << "a: (" << a.getID() << ", " << a.getName() << ")" << endl;
	cout << "b: (" << b.getID() << ", " << b.getName() << ")" << endl;
	cout << "c: (" << c.getID() << ", " << c.getName() << ")" << endl;

	return 0;
}