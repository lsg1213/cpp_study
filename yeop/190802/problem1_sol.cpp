// 부모의 무언가를 건드려서 컴파일은 되지만 
// 이상한 코드가 되었다.
// 이를 수정해 보자. 

#include<iostream>
using namespace std;

class CMyDataA{
public: 
    CMyDataA(){
        cout << "CMyDataA()" << endl;
        m_pszData = new char[32];
    }
    ~CMyDataA(){
        cout << "~CMyDataA()" << endl;
        delete m_pszData;
    }
protected:
    char *m_pszData;
};

class CMyDataB : public CMyDataA{
    public:
        CMyDataB(){
            cout << "CMyDataB()" << endl;
        }
        ~CMyDataB(){
            cout << "~CMyDataB()" << endl;
        }
};
class CMyDataC : public CMyDataB{
    public:
        CMyDataC(){
            cout << "CMyDataC()" << endl;
        }
        ~CMyDataC(){
            cout << "~CMyDataC()" << endl;
            // delete m_pszData; 삭제해야하는 코드
        }
};

int main(){
    cout << "main begin" << endl;

    CMyDataC data;

    cout << "main end" << endl;

}
