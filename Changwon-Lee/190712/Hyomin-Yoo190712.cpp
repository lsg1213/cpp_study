//	3명의 학생의 성적의 평균을 내는 정적 멤버를 클래스 안에 작성한다.
#include <iostream>
using namespace std;

class Score {
private:
	int Eng;

public:
	Score() : Eng(0) {}
	Score(int Eng) : Eng(Eng) {}
	
	static int avr(Score a, Score b, Score c){
		return (a.Eng + b.Eng + c.Eng)/3;
	}
};


int main() {
	Score a(10), b(20), c(30);

	cout << "Average : " << Score::avr(a,b,c) << endl;
}
