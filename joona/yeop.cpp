#include<iostream>

using namespace std;

class Robot{
	int x=0, y=0;
	int life = 5;
	int power = false;

public:
	void setPower(int n){
		power = n;
	}

	int getPower(){
		life = life -1;
		if(life <0){
			cout << "end" << endl;
			power = false;
		}
		return power;
	}
	
	void moveUp(int n){
		int tmp= y + n;
		if (tmp > 10){
			y = 10;
			cout << "움직일 수 있는 범위를 넘었습니다." << endl;
		}
		else{ 
			y = tmp;
		}
	}
	void moveDown(int n){
		int tmp= y - n;
		if (tmp < 0){
			y = 0;
			cout << "움직일 수 있는 범위를 넘었습니다." << endl;
		}
		else{
			y = tmp;
		}
	}
	void moveRight(int n){
		int tmp= x + n;
		if (tmp > 10){
			x = 10;
			cout << "움직일 수 있는 범위를 넘었습니다." << endl;
		}
		else{
			x = tmp;
		}
	}
	void moveLeft(int n){
		int tmp= x - n;
		if (tmp < 0){
			x = 0;
			cout << "움직일 수 있는 범위를 넘었습니다." << endl;
		}
		else{ 
			x = tmp;
		}
	}
	void printLocation(){
		cout << x << " " << y << endl;
	}


};


int main(){
	int move, num;
    Robot robot;
    robot.setPower(true);
    robot.printLocation();

    while (robot.getPower()) {
        cout << "어디로이동? (1.up / 2.down / 3. left / 4.right): ";
        cin >> move;
        cout << "얼마만큼 이동? : ";
        cin >> num;
        if (num < 0) {
            cout << "잘못 입력" << endl;
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
            cout << "잘못입력" << endl;
        }

        cout << endl;
    }   


}
