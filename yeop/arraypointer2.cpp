#include<iostream>

using namespace std;

int main(){
	int arr[2][3] = {{1,2,3},{4,5,6}};
	int arr1[3] = {7,8,9};
		
	int (&ptr_arr)[3] = arr1;
	ptr_arr[1] = 10;
	cout << ptr_arr[1] << endl;		

	int &row1 = arr1[0];
	int *ptr_row1 = &arr1[0];
	cout << "ptr_row1 : " << *ptr_row1 <<endl;
	cout << "arr1[0]: " << row1<< endl;
	
	
	int (&row)[3] = arr[0];
	int &col = row[1];
	
	for(int (*row)[3] = &arr[0]; row < arr +2; row++){
		cout << row+1 << endl;
		cout << *row+1 << endl;
	}

	for(int (*row)[3] = &arr[0]; row < arr+2; row++){ // row = &arr[0]
		for(int *col = ;   <  +3; ++){
			cout << *col << " ";
		}
		cout << endl; 	
	}

	
	



	cout << col << endl;
	cout << row[1]<< endl;
    cout << arr[0] << endl;  // arr1 == arr[0] 주소가 들어있네.

	cout << arr[0][0] << endl;
	
	
}
