#include<iostream>

using namespace std;

class Rectangle{
	int h,w;


public:
	void setRectangle(int m, int n){
		if( m <= 100 && m >= 0 && n <= 100 && n >= 0){
		h = m;
		w = n;	
		}
		else {
		cout << "error" << endl;
		}
	}
	void printArea(){
		cout << "area : "  << h*w<< endl;
	}
	
};



int main(){
	int h(0), w(0);
	Rectangle r;
	cout<<  "h w : ";
	cin >> h >> w;

	r.setRectangle(h,w);
	r.printArea();
	
	

}
