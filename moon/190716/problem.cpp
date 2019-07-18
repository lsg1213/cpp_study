/* *
 * DO NOT use other libraries!!! such as <string.h> or <cstring>
 * */

#include <iostream>
using namespace std;

class MyString {

friend ostream& operator<< (ostream &os, const MyString& myString);

private:
    static int cnt;
    int id;
    char *ptrStr;
    size_t length;

public:
    /* *
     * Constructor
     * You can create an instance like below expressions.
     * ex)
     *   MyString s1("Hello");
     *   MyString s2 = MyString("Hello");
     *   MyString s3 = "Hello";
     *   MyString *s4 = new MyString("Hello");  <- dynamic allocation
     * */
    MyString (const char *str) : id(cnt++) {
        
        // Your code 1

        // For logging
        cout << "Normal Constructor is called. ";
        cout << "\"" << ptrStr << "\" is created! (ID: " << id << ")" << endl;
    };

    /* *
     * Copy Constructor (Deep Copy)
     * User can use below syntax.
     * ex)
     *   MyString s1 = "Hello";
     *   MyString s2(s1);
     *   ( s2 == "Hello" )
     * */
    MyString (const MyString &myString) {
        length = myString.length;
        ptrStr = new char[length + 1];

        for (int i = 0; i < length + 1; i++) {
            ptrStr[i] = myString.ptrStr[i];
        }

        // For logging
        cout << "Copy Constructor is called. ";
        cout << "\"" << ptrStr << "\" is created! (ID: " << id << ")" << endl;
    }

    // Destructor
    ~MyString() {
        delete[] ptrStr;

        cout << "Destructor is called. ";
        cout << "\"" << ptrStr << "\" is deleted! (ID: " << id << ")" << endl;
    }

    /* * 
     *  User can access and modify characters of this instance
     *  using this method.
     *  ex)
     *    MyString s1 = "Hello";
     *    s1[3] = '2';
     *    ( s1 == "Hel2o")
     * */
    char& operator[] (int index) {

        // Your code 2

    };

    /* *
     *  Implementation of string concantenation.
     * */
    MyString operator+ (const MyString& str) {
        char *newStr = new char[length + str.length + 1];
        
        size_t i = 0;
        size_t j = 0;

        while(ptrStr[i] != '\0') {
            newStr[i + j] = ptrStr[i];
            i++;
        }

        while (str.ptrStr[j] != '\0') {
            newStr[i + j] = str.ptrStr[j];
            j++;
        }
        newStr[i + j] = '\0';

        MyString newMyString(newStr);
        delete[] newStr;

        return newMyString;
    };

    /* *
     *  Implementation of string repetition.
     *  ex) 
     *    MyString s1 = "HI";
     *    MyString s2 = s1 * 4;
     *    ( s2 == "HIHIHIHI" )
     * */
    MyString operator* (int num) {
        
        // Your code 3

    };
};

/* *
 * Overload the operator "<<" to use statment like 'cout << myString'.
 * */
ostream& operator<< (ostream &os, const MyString& myString) {
    cout << myString.ptrStr;
    return os;
}

int main() {
    MyString s1 = "snow";
    MyString s2(s1);

    s2[0] = 'k';
    
    MyString s3 = s1 + s2;
    MyString s4 = s3 * 3;

    cout << s4 << endl;
    cout << s3 << endl;
    cout << s2 << endl;
    cout << s1 << endl;

    return 0;
}