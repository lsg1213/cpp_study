#include <iostream>

using namespace std;

class MyClass{
	MyClass(){
		cout << "생성자 호출"<<endl;
	}
	~MyClass(){
		cout <<"소멸자 호출"<<endl;
	}
	void PrintThis(){
		cout << this << endl;
	}
};

int main(){
	MyClass a;

	a.PrintThis();

	return 0;
}