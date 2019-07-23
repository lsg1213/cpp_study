#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string str[100];
	
	int i = 0;
	do {
		getline(cin, str[i]);
		i++;
	} while (str[i-1][0] != '\0');

	for (int j = 0; j < i; j++) {
		cout << str[j] << endl;
	}
	
}