#include <iostream>
using namespace std;

class Robot {
	bool power = false;
	int upDown = 0, leftRight = 0;
	int limit = 5;

public:
	void setPower(bool p) {
		power = p;
		if (power == true) {
			cout << "전원이 켜졌습니다." << endl;
		}
		else {
			cout << "전원이 꺼졌습니다." << endl;
		}
	}

	bool getPower() {
		return power;
	}


	void moveUp(int up) {
		if (upDown + up <= 10) {
			upDown += up;
			limit--;
			if (limit == 0) {
				setPower(false);
			}
		}
		else {
			cout << "움질일 수 있는 범위를 넘어섰습니다." << endl;
		}

	}

	void moveDown(int down) {
		if (upDown - down >= 0) {
			upDown -= down;
			limit--;
			if (limit == 0) {
				setPower(false);
			}
		}
		else {
			cout << "움질일 수 있는 범위를 넘어섰습니다." << endl;
		}

	}

	void moveLeft(int left) {
		if (leftRight - left >= 0) {
			leftRight -= left;
			limit--;
			if (limit == 0) {
				setPower(false);
			}
		}
		else {
			cout << "움질일 수 있는 범위를 넘어섰습니다." << endl;
		}
	}

	void moveRight(int right) {
		if (leftRight + right >= 0) {
			leftRight += right;
			limit--;
			if (limit == 0) {
				setPower(false);
			}
		}
		else {
			cout << "움질일 수 있는 범위를 넘어섰습니다." << endl;
		}
	}

	void printLocation() {
		cout << "현재 위치는 (" << upDown << ", " << leftRight << ") 입니다." << endl;
	}

};


int main() {
	int move, num;
	Robot robot;
	robot.setPower(true);
	robot.printLocation();

	while (robot.getPower()) {
		cout << "로봇이 움직이는 방향을 선택하시요 (1.up / 2.down / 3. left / 4.right): ";
		cin >> move;
		cout << "로봇이 얼마만큼 움직일지 입력하시오: ";
		cin >> num;
		if (num < 0) {
			cout << "잘못입력하셨습니다" << endl;
			continue;
		}

		switch (move) {
		case 1:
			robot.moveUp(num);
			robot.printLocation();
			break;
		case 2:
			robot.moveDown(num);
			robot.printLocation();
			break;
		case 3:
			robot.moveLeft(num);
			robot.printLocation();
			break;
		case 4:
			robot.moveRight(num);
			robot.printLocation();
			break;
		default:
			cout << "잘못입력하셨습니다" << endl;
		}

		cout << endl;
	}
}