#include <iostream>
#include <cstring>

using namespace std;

class CTestData
{
public:
    CTestData(){
        cout << "CTestData() " << this << endl;
        m_nData = 0;
        str = NULL;
    }
	CTestData(int nparam,char* string) : m_nData(nparam){ 
        cout << "CTestData(int, char*) " << this << endl; 
        str = new char[strlen(string) + 1];
        strcpy(str, string);
    }
	~CTestData() { 
        cout << "~CTestData() " << this << endl; 
        delete[] str;
    }

	CTestData(const CTestData &rhs)
		: m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &) " << this <<endl;
	    str = new char[strlen(rhs.str)+1];
        strcpy(str, rhs.str);
    }

/*	CTestData(CTestData &&rhs)
		: m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &&) " << this  << endl;
        str = rhs.str;
        rhs.str = NULL;
	}

	CTestData& operator=(CTestData &&rhs)
	{
		cout << "CTestData& operator=(const CTestData &&) " << this << endl;
		m_nData = rhs.m_nData;
        str = rhs.str;
        rhs.str = NULL;
		return *this; 
	}
*/
	int GetData() const { return m_nData; }
	void SetData(int nParam, char* string) { 
        m_nData = nParam; 
        str = new char[strlen(string)+1];
        strcpy(str, string);
    }

private:
	int m_nData = 0;
    char *str;
};

CTestData TestFunc(int nParam, char* string)
{
	cout << "**TestFunc(): Begin***" << endl;
	CTestData a;
	a.SetData(nParam, string);
	cout << "**TestFunc(): End*****" << endl;
	return a;
}

int main()
{
	CTestData b(1,"yeop");
	cout << "*Before***************" << endl;
	b = TestFunc(10, "jeong");
	cout << "*After****************" << endl;
	CTestData c(b);
	return 0;
}
