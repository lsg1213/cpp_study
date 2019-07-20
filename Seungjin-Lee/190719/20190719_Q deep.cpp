// Deep copy와 Shallow copy의 출력값 차이 확인하기
// Deep과 Shallow 두 가지 경우를 완성하기

#include <iostream>
#include <cstring>
using namespace std;

class Member
{
public:
    int age;
    char* name;

public:
    Member(int _age, char* _name) //Constructor
    {
        age = _age;
        name = new char [strlen(_name)+1];
        strcpy(name, _name);
    }

    Member(const Member& s) 
    {
        age = s.age;
        name = new char [strlen(s.name) + 1];
        strcpy(name, s.name);
    }

    ~Member() {delete name;}

    void printMember()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
};

int main()
{
    Member Q(23, "Mr.ABc");
    Member W = Q;

    Q.age = 24;
    strcpy(Q.name, "Mr.QWc");

    Q.printMember();
    W.printMember();

    return 0;
}
