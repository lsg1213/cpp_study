#include <iostream>

using namespace std;

class Vector{
private:
	float x;
	float y;
	
public:
	Vector();
	Vector(float x, float y);
	float GetX() const;
	float GetY() const;
	static Vector Sum(Vector a, Vector b);
	Vector Add(Vector b);
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

Vector::Vector() : x(0), y(0) {}
Vector::Vector(float x, float y) : x(x), y(y) {}
float Vector::GetX() const {return x;}
float Vector::GetY() const {return y;}
Vector Vector::Add(Vector b){
		return Vector(x + b.GetX(), y + b.GetY());
	}
Vector Vector::Sum(Vector a, Vector b){
		return Vector(a.GetX() + b.GetX(), a.GetY() + b.GetY());
	}
