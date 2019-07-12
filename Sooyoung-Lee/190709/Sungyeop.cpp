// constructor, destructor
// (1)  how many destructors are printed after main?
// (2)  please predict constructor and destructor order !!  

#include<iostream>
using namespace std;

class Myclass {

public:
	Myclass() {
		cout << "constructor called for " << this << endl;
	}
	~Myclass() {
		cout << "destructor called for " << this << endl;
	}

};

Myclass d;

int main() {
	cout << "main start" << endl;

	Myclass a;
	{Myclass b; }

	if (1) {
		Myclass c;
	}

	cout << "main end" << endl;

}

/*
	1


	d
	main start
	a
	b
	~b
	c
	~c
	main end
	~a
	~d

*/


