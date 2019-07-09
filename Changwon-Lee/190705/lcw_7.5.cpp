#include<iostream>
#include<string>

using namespace std;

int main(){
	char str[100][100];
	int i = 0;
	
	do{
		cin.getline(str[i], 100);
		i++;
	}while(str[i-1][0] != '\0');
	
	for(int j = 0; j < i-1; j++){
		cout << str[j] << endl;
	}
}

