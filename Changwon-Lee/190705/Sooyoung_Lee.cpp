#include<iostream>
#include<string>

using namespace std;

class rec{
	private :
		int x, h;
		
	public :
		setx(int width){
			x = width;
		}
		seth(int height){
			h = height;
		}
		getarea(){
			cout << "area : " << x*h << endl;
		}
};

int main(){

	int a, b;
	rec c;
	
	cout << "width : ";
	cin >> a;
	cout << "height : ";
	cin >> b;
	
	c.setx(a);
	c.seth(b);
	
	c.getarea();
	
}
