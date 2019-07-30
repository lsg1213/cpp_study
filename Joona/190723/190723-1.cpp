#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>

//구조체와 클래스의 크기를 이해한다.
//구조체와 클래스에서 깊은 복사를 통해 그 내용을 완벽하게 복사한다. 

//혈액형을 뜻하는 문자열들은 모두 그 길이가 3으로 고정되며, 그 이외의 문자열을 입력값으로 받지 않도록 한다.
//단,예외처리를 할 필요는 없다. 

//구조체와 클래스의 내용물은 각각 자신의 혈액형을 나타내는 혈액형, 부모님의 혈액형, 나이, 성적이다.
//이를 최적의 경우와 최악의 경우의 구조체와 클래스의 크기를 각각 구하여라. 

using namespace std;

class c_person {
private:
	char* blood;
	char* f_b;
	char* m_b;
	int age;
	float grade;

public:
	c_person() {//입력값이 아무것도 주어지지 않았을 경우의 기본적인 생성자.  
		blood = new char[3];
		f_b = new char[3];
		m_b = new char[3];
		age = 30;
		grade = 3.0;
		blood = "AA";
		f_b = "AA";
		m_b = "AA";
	}

	//입력값이 주어졌을 때의 생성자. 
	c_person(char* self, char* father, char* mother, int age, float grade) : age(age), grade(grade) {
		blood = new char[3];
		f_b = new char[3];
		m_b = new char[3];
		strcpy(blood, self);
		strcpy(f_b, father);
		strcpy(m_b, mother);
	}

	//생성자의 입력값이 같은 class의 객체로 주어졌을 때의 경우, 생성자를 작성하라. 
	c_person(const c_person& person) {
		blood = new char[3];
		f_b = new char[3];
		m_b = new char[3];
		age = person.age;
		grade = person.grade;
		strcpy(blood, person.blood);
		strcpy(f_b, person.f_b);
		strcpy(m_b, person.m_b);
	}

	//show 함수를 참고하여 class를 완성하라. 
	void show() {
		cout << "age : " << age << endl;
		cout << "grade : " << grade << endl;
		cout << "blood type : " << blood << endl;
		cout << "father's blood type : " << f_b << endl;
		cout << "mother's blood type : " << m_b << endl;
	}
};

struct s_person {//구조체를 최소/최대의 크기를 가지는 조건으로 완성해보아라.  
	char* blood;
	int age;
	char* f_blood;
	float grade;
	char* m_blood;
};


void copy(struct s_person &a, struct s_person &b) {//다른 구조체를 깊은 복사하는 함수를 작성하라. 
	delete[] a.blood;
	delete[] a.f_blood;
	delete[] a.m_blood;
	a.blood = new char[3];
	a.f_blood = new char[3];
	a.m_blood = new char[3];
	strcpy(a.blood, b.blood);
	strcpy(a.f_blood, b.f_blood);
	strcpy(a.m_blood, b.m_blood);
	a.age = b.age;
	a.grade = b.grade;
}


void show(struct s_person person) {
	cout << "age : " << person.age << endl;
	cout << "grade : " << person.grade << endl;
	cout << "blood type : " << person.blood << endl;
	cout << "father's blood type : " << person.f_blood << endl;
	cout << "mother's blood type : " << person.m_blood << endl;
}

int main() {
	c_person clee = c_person("AA", "aa", "bb", 25, 4.42);
	s_person slee;
	s_person clone;

	slee.age = 24;
	slee.grade = 3.0;
	slee.blood = new char[3];
	slee.f_blood = new char[3];
	slee.m_blood = new char[3];
	slee.blood = "AA";
	slee.f_blood = "AA";
	slee.m_blood = "AA";


	//class person의 크기를 출력하시오 
	cout << "sizeof(lee) : " << sizeof(clee) << endl;
	cout << "sizeof(lee2) : " << sizeof(slee) << endl;


	//출력 및 확인 부분. 
	clee.show();
	show(slee);
	copy(slee, clone);
	show(clone);

	return 0;
}