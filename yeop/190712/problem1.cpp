#include<iostream>
using namespace std;


int main(){

	int a(0);
	int b(0);

	const int & ref = a;
	const int * ptr = &b;	
	// print : 0
	cout << ref << endl;
	cout << *ptr << endl;
	
	// fill the below
	


	// print : 1
	cout << ref << endl;
	cout << *ptr << endl;

}
