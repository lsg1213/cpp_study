#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define N 10

class MyClass {
public:
	long long unsigned int GetOffsetFrom(MyClass* myClass) {
		/**
		 *  현재의 객체와 다른 객체의 인덱스 차이(offset)를
		 *  리턴하는 함수
		 *
		 */
		MyClass *a = myClass;
		MyClass *b = this;
		long long unsigned int n = abs(a - b)/sizeof(MyClass);

		return n;
	}
};

class MyArray {
private:
	int arrSize;
public:
	MyClass* arr;

	/**
	 * 아래의 코드를 변경하여 private 필드의 arrSize의 값을
	 * 매개변수 값으로 초기화 시키세요.
	**/
	MyArray(int n) {
		arr = new MyClass[n];
		arrSize = n;
		srand(time(NULL));
	}

	// 이후의 코드는 변경하지 마세요
	~MyArray() {
		delete[] arr;
	}
	MyClass* GetElementRadomlyOnRange(int& index) {
		int num = rand() % arrSize;
		index = num;
		return arr + num;
	}
};


int main() {
	MyArray myArray(N);

	// 정답확인을 위한 변수
	int rand1, rand2;

	// 랜덤한 두 객체를 뽑는다.
	MyClass* m1 = myArray.GetElementRadomlyOnRange(rand1);
	MyClass* m2 = myArray.GetElementRadomlyOnRange(rand2);

	// 두 객체 사이의 index 차이(offset)를 출력
	cout << "정답: " << abs(rand1 - rand2) << endl;
	cout << "계산한 답: " << (*m1).GetOffsetFrom(m2) << endl;

	return 0;
}