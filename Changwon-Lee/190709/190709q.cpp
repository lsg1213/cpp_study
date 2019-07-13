#include<iostream>

using namespace std;

class chin{
private:
   char c;
   int i;

public:
   //c = 'a'로 i = 15로 초기화 해주는 생성자를 작성하시오. 
   chin() : c = 'a', i = 15{}
   void show(){
      cout << "c : " << c << endl;
      cout << "i : " << i << endl;
   }
};
 

int main(){
   chin a;
   
   //class chin a의 크기를 출력하시오 
   cout << "sizeof(a) : " << sizeof(a) << endl;
   
   a.show();
   
   
   //접근제한자를 고려하지 말고 포인터를 통하여 
   //a의 멤버를 각각 c = 'b'로 i = 20으로 바꾸어라 

   
   //해설을 위한 값
   
   printf("%d\n", p);
   printf("%d\n", p+4);
   
   //
   a.show();
}