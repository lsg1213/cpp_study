// constructor, destructor
// (1)  how many destructors are printed after main?
//4
// (2)  please predict constructor and destructor order !!  
//d持失, main start, a持失, b持失, b社瑚, c持失, c社瑚, main end, a社瑚, d社瑚

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

