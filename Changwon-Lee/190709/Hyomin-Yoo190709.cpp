//MyClass를 완성하여 생성자, 소멸자의 호출을 확인시기를 확인하고 PrintThis함수로 a의 주소를 출력한다. 

#include <iostream>

using namespace std;

class MyClass{
public :
	
	MyClass(){
		cout << "craete" << endl;
	}
	
	~MyClass(){
		cout << "delete" << endl;
	}
	
	void PrintThis(){
		cout << this << endl;
	}
};

int main(){
	MyClass a,b;

	a.PrintThis();
	
	return 0;
}
