#include<iostream>
using namespace std;

void printarr(int *arr){
	for(int i = 0; i < 4; i++){
		cout << *(arr+i) << endl;
	}
}

int main(){
	int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	
	cout <<	arr << endl;
	cout << &arr << endl;
	cout << &arr[0] << endl;

	cout << (arr+1) << endl;
	cout << &arr + 1 << endl;
	cout << &arr[0]+1 << endl;
	cout << *arr +1 << endl;


}
