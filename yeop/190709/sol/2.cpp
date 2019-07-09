#include <iostream>

using namespace std;

class MyClass{
public:
		
	MyClass(){
		cout << "constructor"<<endl;
	}
	~MyClass(){
		cout <<"destructor"<<endl;
	}
	void PrintThis(){
		cout << this << endl;
	}
};

int main(){
	MyClass a,b;

	a.PrintThis();
}
