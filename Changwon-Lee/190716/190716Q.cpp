#include <iostream>

//divide definition and declaration

using namespace std;

class Vector{
private:
	float x;
	float y;
	
public:
	Vector() : x(0), y(0) {}
	Vector(float x, float y) : x(x), y(y) {}
	float GetX() const{
		return x;
	}
	float GetY() const{
		return y;
	}
	Vector Add(Vector b){
		return Vector(x + b.GetX(), y + b.GetY());
	}
	static Vector Sum(Vector a, Vector b){
		return Vector(a.GetX() + b.GetX(), a.GetY() + b.GetY());
	} 
}; 

int main(){
	Vector a(2,3);
	Vector b(-1,4);
	Vector c = Vector::Sum(a,b);
	Vector d = a.Add(b);
	 
	cout << a.GetX() << " " << a.GetY() << endl;
	cout << b.GetX() << " " << b.GetY() << endl;
	cout << c.GetX() << " " << c.GetY() << endl;
	cout << d.GetX() << " " << d.GetY() << endl;
	
	return 0;
} 
