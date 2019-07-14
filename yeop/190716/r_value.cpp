#include<iostream>
using namespace std;

int Add(int a, int b){
	
	return a+b;
}

int main(){
	int a(3), b(5);
	int &&result = Add(a,b);

	cout << &result << endl;
	
}
