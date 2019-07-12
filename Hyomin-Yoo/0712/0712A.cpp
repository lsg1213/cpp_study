#include <iostream>
using namespace std;


class Score {
private:
	int Eng;

public:
	Score() : Eng(0) {}
	Score(int Eng) : Eng(Eng) {}

	static Score AVG(Score a, Score b) {
		return Score((a.Eng + b.Eng) / 2);
	}
};

int main() {
	Score a(60);
	Score b(70);

	Score avg = Score::AVG(a, b);

	cout << "ЦђБе : " << avg.AVG;
}