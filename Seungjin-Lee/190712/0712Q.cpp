//	2명의 학생의 성적의 평균을 내는 정적 멤버를 클래스 안에 작성한다.
#include <iostream>
using namespace std;


class Score {
private:
	int Eng;

public:
	Score() : Eng(0) {}
	Score(int Eng) : Eng(Eng) {}
	static int aver(Score Eng1, Score Eng2) {
		return (Eng1.Eng+Eng2.Eng)/2;
	}
};

int main() {
	Score a(50), b(60);

	cout << "평균 : " << a.aver(a,b) << endl;
}