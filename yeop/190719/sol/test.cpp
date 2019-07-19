#include<iostream>
using namespace std;


int main(){
	int i = 3;
	int *pi;
	int **ppi;

	pi = &i;
	*ppi = pi;

	cout << **ppi << endl;
	cout << *ppi << endl;
	cout << *pi << endl;
	cout << pi << endl;

}
