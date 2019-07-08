/*
다음 클래스의 정의에서 생성자 오버로딩을 이용하지 않고,
아래의 코드가 정상적으로 수행되도록 생성자의 정의를 수정하세요.

출력 결과 :	0 0
2 3
*/

#include <iostream>

using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 =0) // 디폴트 값을 이용하면 된다
	{
		num1 = n1;
		num2 = n2;
	}

	void Show() const
	{
		cout << num1 << ' ' << num2 << endl;
	}

};


int main(void)
{
	SimpleClass sc1;
	sc1.Show();

	SimpleClass sc2(2, 3);
	sc2.Show();

	return 0;
}