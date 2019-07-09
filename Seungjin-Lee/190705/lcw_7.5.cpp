#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	string b;
		
	while (getline(cin, a)) {
		if (a == "\0") break;
		b += a + "\n";
	}
	cout << b;
	return 0;
}