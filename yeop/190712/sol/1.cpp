#include <iostream>
using namespace std;


class Score {
private:
	int Eng;

public:
	Score() : Eng(0) {}
	Score(int Eng) : Eng(Eng) {}

	static int AVG(Score a, Score b) {
		return ((a.Eng + b.Eng) / 2);
	}
};

int main() {
	Score a(60);
	Score b(70);

	int avg = Score::AVG(a, b);

	cout << "Æò±Õ : " << avg << endl;

}
