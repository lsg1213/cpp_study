#include<iostream>

using namespace std;

class robot{
	private:
		bool power = false;
		int x = 0;
		int y = 0;
		int life = 5;
		
	public:
		void move(int dir, int dis){
			if(power == true){
				if(life == 0){
					cout << "Turned off" << endl;
				}
				else if(life == 1){
					life--;
					power = false;
					switch (dir){
						case 1:
							if(x + dis > 10){
								cout << "over limit" << endl;
							}
							else{
								x += dis;
							}
							cout << "X : " << x << "Y : " << y<< endl;
							break;
						case 2:
							if(x - dis < 0){
								cout << "over limit" << endl;
							}
							else{
								x -= dis;
							}
							cout << "X : " << x << "Y : " << y<< endl;
							break;
						case 3:
							if(y + dis > 10){
								cout << "over limit" << endl;
							}
							else{
								y += dis;
							}
							cout << "X : " << x << "Y : " << y<< endl;
							break;
						case 4:
							if(y - dis < 0){
								cout << "over limit" << endl;
							}
							else{
								y -= dis;
							}
							cout << "X : " << x << "Y : " << y<< endl;
							break;
						default:
							break;
					}
				}
				else{
					life--;
					switch (dir){
						case 1:
							if(x + dis > 10){
								cout << "over limit" << endl;
							}
							else{
								x += dis;
							}
							cout << "X : " << x << " " << "Y : " << y<< endl;
							break;
						case 2:
							if(x - dis < 0){
								cout << "over limit" << endl;
							}
							else{
								x -= dis;
							}
							cout << "X : " << x << "Y : " << y<< endl;
							break;
						case 3:
							if(y + dis > 10){
								cout << "over limit" << endl;
							}
							else{
								y += dis;
							}
							cout << "X : " << x << "Y : " << y<< endl;
							break;
						case 4:
							if(y - dis < 0){
								cout << "over limit" << endl;
							}
							else{
								y -= dis;
							}
							cout << "X : " << x << "Y : " << y<< endl;
							break;
						default:
							break;
					}
				}	
			}
			else{
				cout << "Turned off" << endl;
			}	
		}
		
		void turnoff(){
			power = false;
			cout << "Turned off" << endl;
			
		}
		
		void turnon(){
			power = true;
			cout << "Turned on" << endl;
		}
};

int main(){
	robot a;
	a.turnon(); 
	a.move(1, 5);
} 
