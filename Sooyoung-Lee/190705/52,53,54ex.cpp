/*
	직사각형을 정의하는 클래스를 정의하고,
	클래스의 멤버로 직사각형의 면적을 리턴하는 함수를 포함해라
	(직사각형의 넓이와 높이는 각각 0 이상 100 이하로 제한)

	메인함수에 클래스의 멤버를 이용하여 직사각형의 면적을 출력할 것

*/

#include <iostream>

using namespace std;

class Rectangle {
	int width = 0;
	int height = 0;

public: 
	void setWidth(int width_) {
		if(width_ >=0 && width <=100)
			width = width_;
	}
	void setHeight(int height_) {
		if(height_ >=0 && height <=100)
			height = height_;
	}

	int getArea() {
		return width * height;
	}
};

int main() {
	Rectangle A;
	int w, h;
	cout << "직사각형의 넓이 (0 이상 100 이하) : ";
	cin >> w;
	cout << "직사각형의 높이 (0 이상 100 이하) : ";
	cin >> h;

	A.setWidth(w);
	A.setHeight(h);
	
	cout << "직사각형의 면적 : " << A.getArea() << endl;
}