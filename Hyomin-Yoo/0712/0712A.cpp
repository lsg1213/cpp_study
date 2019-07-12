#include <iostream>
using namespace std;


class Score {
private:
	float Eng;

public:
	Score() : Eng(0) {}
	Score(float Eng) : Eng(Eng) {}
	
	float getGrade(){return Eng;}
	static Score AVG(Score a, Score b) {
		return Score((a.Eng + b.Eng) / 2);
	}
};

int main() {
	Score a(60);
	Score b(60);

	Score avg = Score::AVG(a, b);

	cout << "ЦђБе : " << avg.getGrade();
}