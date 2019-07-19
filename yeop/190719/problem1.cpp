// copy constructor problem
// 아래를 실행해 보면 복사 생성자가 실행이 됨을 알 수 있다.
//  TestFunc만 실행 했을 뿐인데,  이는 원치 않는 결과이다. 
// 복사 생성자가 실행이 되지 않도록 고쳐보자.

#include<iostream>

using namespace std;


class Userdata{
private:
	int nAge;
	string szName;

public:
	Userdata() : nAge(0), szName("") { 
		cout << "Userdata() " << endl;
	}
	
	Userdata(int nAge, string szName) : nAge(nAge), szName(szName) { 
		cout << "Userdata(int,string) " << endl;
	}
	
	Userdata(const Userdata &rhs) : nAge(rhs.nAge), szName(rhs.szName) {
		cout << "Userdata(const Userdata &rhs) " << endl; 
	}
		
	void Setdata_nAge(int nParam){
		nAge = nParam;
	}

	static void Printdata(const Userdata *a) {
		cout << a->nAge << " " << a->szName << endl;
	}
};

void TestFunc(Userdata Param){
	cout << "TestFunc() " << endl;
	Param.Setdata_nAge(26);
}

int main(){
	cout << "begin - main" << endl;
	Userdata a(10,"yeop");
	TestFunc(a);

	cout << "end - main" << endl;
}


