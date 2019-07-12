#include <iostream> 
using namespace std; 
  
class student 
{ 
private: 
    const int roll; 
public: 
    // constructor 
    student(int r):roll(r) {} 
  
    // A const function that changes roll with the help of const_cast 
    void fun() const
    {	
		
		// you just change here !
       student *a = const_cast <student*> (this);
       int *b = (int *)a;
       *b = 5;
    } 
  
    int getRoll()  { return roll; } 
}; 
  
int main(void) 
{ 
    student s(3); 
    cout << "Old roll number: " << s.getRoll() << endl; 
  
    s.fun(); 
  
    cout << "New roll number: " << s.getRoll() << endl; 
  
    return 0; 
} 
