#include<iostream>
using namespace std;

int main(){
	int *ptr_a, *ptr_b;

	ptr_a = new int;
	*ptr_a = 10;

	ptr_b = new int;
	ptr_b = ptr_a;
	
	cout << *ptr_a << endl;
	cout << *ptr_b << endl;

	delete ptr_a;
	delete ptr_b;
}
