#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

void swap2(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
	cout << "x:" << x << ", y:" << y << endl;
}

class Robot {
	bool power=false;
	int upDown=0, leftRight=0;
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
		if (upDown - down >=0) {
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

int main()
{
	/*
	float a, b;

	printf("체중(kg):");
	scanf_s("%f", &a, sizeof(a));
	printf("키(m):");
	scanf_s("%f", &b, sizeof(b));

	printf("체질량 지수: %f", a / (b*b));
	

	char c;
	scanf_s("%c", &c, 1);
	printf("next alpah: %c\n", c + 1);
	*/

	/*
	int score;
	scanf_s("%d", &score);

	if (score <0 || score > 100)
		printf("잘못 입력하셨습니다.\n");
	else if (score >= 90) 
		printf("A\n");
	else if (score >= 80) 
		printf("B\n");
	else if (score >= 70) 
		printf("C\n");
	else if (score >= 60) 
		printf("D\n");
	else 
		printf("E\n");
		

	int num;
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			printf("%d, ", i);
		}
	}
	

	int n;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		int k = i % 10;
		if (k == 3 || k == 6 || k == 9) {
			printf("* ");
		}
		else {
			printf("%d ", i);
		}
	}
	printf("\n");
	

	int n;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d ", 2 * j - 1);
		}
		printf("\n");
	}
	*/

	/*
	int n;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * i - 1; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}*/

	/*
	string name;
	int score;

	cout << "이름 입력 : ";
	cin >> name;
	cout << "점수 입력 : ";
	cin >> score;
	cout << name << "님의 점수는 " << score << "점입니다." << endl;
	

	int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

	cout << **arr << endl;
	cout << **(arr + 1) << endl;
	cout << *(*arr + 1) << endl;

	for (int(&ln)[3] : arr) {
		for (int& col : ln) {
			cout << col << ' ';
		}
		cout << endl;
	}

	int num[] = { 1,2, 3 };
	

	//int(&ln)[3] = *arr;
	//cout << "size:" << sizeof(ln) << endl;

	//int (&ln)[3] = *arr;

	
	//for (int* ln : arr) 
		//for (int col : *ln) 
	
	
	for (int(*ln)[3] = arr; ln < arr + 2; ln++) {
		for (int* c = *ln; c < *ln + 3; c++) {
			cout << *c << ' ';
		}
		cout << endl;
	}
	*/

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

