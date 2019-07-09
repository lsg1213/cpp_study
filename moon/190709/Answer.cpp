#include <iostream>
#include <cstdlib>
using namespace std;
#define N 10

class MyClass {
public:
    long long unsigned int GetOffsetFrom(MyClass *myClass) {
        if (this > myClass)
            return (this - myClass) / sizeof(MyClass);
        else
            return (myClass - this) / sizeof(MyClass);
        
    }
};

class MyArray {
private:
    int arrSize;
public:
    MyClass *arr;
    MyArray(int n) : arrSize(n) {
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

    // 정답확인을 위한 변수
    int rand1, rand2;
    
    // 랜덤한 두 객체를 뽑는다.
    MyClass *m1 = myArray.GetElementRadomlyOnRange(rand1);
    MyClass *m2 = myArray.GetElementRadomlyOnRange(rand2);

    // 두 객체 사이의 index 차이(offset)를 출력
    cout << "정답: " << abs(rand1 - rand2) << endl;
    cout << "계산한 답: " << (*m1).GetOffsetFrom(m2) << endl;
    return 0;
}