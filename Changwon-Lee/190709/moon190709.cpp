#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 10

class MyClass {
public:
    long long unsigned int GetOffsetFrom(MyClass *myClass) {
     	return abs(this - myClass);
    }
};

class MyArray {
private:
    int arrSize;
public:
    MyClass *arr;

    MyArray(int n) {
    	arrSize = N;
        arr = new MyClass[n];
        srand(time(NULL));
    }

   
    ~MyArray() {
        delete[] arr;
    }
    MyClass *GetElementRadomlyOnRange(int &index) {
        int num = rand()%arrSize;
        index = num;
        return arr + num;
    }
};


int main() {
    MyArray myArray(N);
  
    int rand1, rand2;
    
    MyClass *m1 = myArray.GetElementRadomlyOnRange(rand1);
    MyClass *m2 = myArray.GetElementRadomlyOnRange(rand2);

    cout << "Answer : " << abs(rand1 - rand2) << endl;
    cout << "Calc " << (*m1).GetOffsetFrom(m2) << endl;
    
    return 0;
}
