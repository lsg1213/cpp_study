/* *
 * DO NOT use other libraries!!! such as <string.h> or <cstring>
 * */

#include <iostream>
using namespace std;

class MyString {
private:
    char *ptrStr;
    size_t length;
public:
    // Constructors
    MyString() {}
    MyString (const char *str) {
        size_t size = 0;
        while (str[size++] != '\0') {}

        ptrStr = new char[size];

        for (int i = 0; i < size; i++) {
            ptrStr[i] = str[i];
        }

        length = size - 1;
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
    }

    // Destructor
    ~MyString() {
        delete[] ptrStr;
    }

    /* *
     * This method creates a new array of characters and return its address.
     * */
    char *to_char() const {
        return (MyString(*this)).ptrStr;
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
        return ptrStr[index];
    };

    /* *
     *  Implementation of string concantenation.
     * */
    MyString& operator+ (MyString str) {
        MyString *new_str = new MyString();
        
        new_str->length = length + str.length;
        new_str->ptrStr = new char[new_str->length + 1];
        
        size_t i = 0;
        size_t j = 0;

        while(ptrStr[i] != '\0') {
            new_str->ptrStr[i + j] = ptrStr[i];
            i++;
        }

        while (str.ptrStr[j] != '\0') {
            new_str->ptrStr[i + j] = str.ptrStr[j];
            j++;
        }

        new_str->ptrStr[i + j] = '\0';
        return *new_str;
    };

    /* *
     *  Implementation of string repetition.
     *  ex) 
     *    MyString s1 = "HI";
     *    MyString s2 = s1 * 4;
     *    ( s2 == "HIHIHIHI" )
     * */
    MyString& operator* (int num) {

    };
};

/* *
 * Overload the operator "<<" to use statment like 'cout << myString'.
 * */
ostream& operator<< (ostream &os, const MyString myString) {
    cout << myString.to_char();
    return os;
}

int main() {
    MyString s1 = "CPP_STUDY";
    MyString s2;

    cout << s2 << '\n';

    return 0;
}