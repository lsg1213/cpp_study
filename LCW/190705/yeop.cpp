#include<iostream>

using namespace std;

int main(){
	string s[101];
	int i = 0;
	while(1){
		getline(cin, s[i]);
		if(s[i].length() == 0)
			break;
		i++;
	}

	for(int j = 0; j < i; j++){
		cout << s[j] << endl;
	}
	
	

}
