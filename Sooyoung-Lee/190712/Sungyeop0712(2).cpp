// this time, we learn about const. 
// const_cast is used to cast away the constness of variables.
// using const_cast() and this pointer, we can change GetData method possible to change const variables. 

#include<iostream>

using namespace std;

class Myclass {
private:
	mutable int mutable_var;
	int a;

public:
	Myclass() : mutable_var(0), a(0) { }
	void SetData() {

	}
	int GetData_a() const {

		// make possible to change variabe a to 20
		const_cast<int&>(a) = 20;

		return a;
	}

};

int main() {
	Myclass a;

	cout << a.GetData_a() << endl;
}
