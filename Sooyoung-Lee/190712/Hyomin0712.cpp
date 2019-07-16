//	3명의 학생의 성적의 평균을 내는 정적 멤버를 클래스 안에 작성한다.
#include <iostream>
using namespace std;


class Score {
private:
	int Eng;
	static int Sum;
	static int Count;

public:
	Score() : Eng(0) { Sum += Eng; Count++; }
	Score(int Eng) : Eng(Eng) { Sum += Eng; Count++; }
	static double Average() {
		return (double)Sum / Count;
	}
};

int Score::Sum = 0;
int Score::Count = 0;

int main() {

	Score a(30);
	Score b(78);
	Score c(49);


	cout << "평균 : " << Score::Average() << endl;
}