#include<iostream>

using namespace std;

int strlen(const char *str) {
	int len = 0;
	while(str[len] != '\0'){
		len++;
	}
	return len;
}

class MyString{
private: 
	char *string_con;
	int string_len;

public:
	MyString() : string_len(0),string_con(nullptr) { }
	MyString(char c){
		string_len = 1;
		string_con = new char[0];
		string_con[0] = c;
	}
	MyString(const char *str){
		string_len = strlen(str);
		string_con = new char[string_len+1];
		
		for(int i = 0; i <= string_len; i++){
			string_con[i] = str[i];
		}
	}
	MyString(const MyString &myString) {
		string_len = myString.string_len;
		string_con = new char[string_len + 1];
  
          for (int i = 0; i < string_len + 1; i++) {
              string_con[i] = myString.string_con[i];
          }
      }

	MyString& operator+(const MyString &str){
		MyString *result = new MyString();		
		
		result->string_len = str.string_len + string_len;
		result->string_con = new char[result->string_len + 1];
		
		int i = 0;
		int j = 0;

		for(i = 0; i < string_len; i++)
			result->string_con[i+j] = string_con[i];

		for(j = 0; j < str.string_len; j++)
			result->string_con[i+j] = str.string_con[j];

		result->string_con[i+j] = '\0';
		
		cout <<"result " << result->string_con << endl;
		return *result;
	}
	 
	MyString& operator* (const int num) {

        MyString *result = new MyString();

        result->string_len = num *string_len;
        result->string_con = new char[result->string_len + 1];

        for(int i = 0; i < num; i++){
            for(int j = 0; j < string_len; j++){
                result->string_con[string_len*i+j] = string_con[j];
            }
        }
        result->string_con[num*string_len] = '\0';
        return *result;

    }
	MyString& insert(const int loc, const MyString& str);	

	char at(const int n) const{
		if(string_len <= n || n < 0)
			return -1;
		else 
			return string_con[n];
	}

	int strcmp(const MyString &str1, const MyString &str2){
		
		int i = 0;
		if( str1.string_len == str2.string_len){
		
		while(str1.string_con[i] != '\0' &&  str2.string_con[i] != '\0'){
			if(str1.string_con[i] != str2.string_con[i]){ 
			if(str1.string_con[i] < str2.string_con[i])
				return 1;
			else 
				return -1;
			}
			i++;
		}
		if(i == str1.string_len)
			return 0;
		}
	}
	
	// 문자가 있으면 그 위치 반환, 없으면 -1반환
	int find(const char *str, int pos = 0){
		
		int len = strlen(str);
		int j = 0;
		int flag = false;
		while(string_con[pos] != '\0'){
			
			for(int k =0; k < len; k++){
				if(string_con[pos+k] != str[k])
					break;
				if(k==len){}
			}
		
			pos++;
			j++;
		}
	return 0;	
	}

	int length() const { return string_len; }
	void print() const { cout << string_con << endl; } 
	char* GetString() const { return string_con; }	
	
	~MyString(){ delete[] string_con; }
	


};

MyString& MyString::insert(const int loc, const MyString& str){
	
	// your code 
	if( loc >= string_len || loc < 0) return *this;

	
	char *prev_string_con = string_con;
	string_con = new char[string_len + 1];
	
	int i;
	for(i = 0; i < loc; i++){
		string_con[i] = prev_string_con[i];
	}


	for(int j = 0; j < loc+str.string_len; j++){
		string_con[i+j] = str.string_con[j];
	}

	for(i = loc; i < string_len; i++){
		string_con[i+str.string_len] = prev_string_con[i];
	}
	
	delete[] prev_string_con;
	string_len = string_len + str.string_len;

	return *this;

}

ostream& operator<< (ostream &os, const MyString &str){
		cout << str.GetString();
		return os;
}

int main(){
	MyString a("yeop");
	a.print();
	MyString b("seong");
	b.print();
	
	a.insert(2,"s");
	a.print();
	
}
