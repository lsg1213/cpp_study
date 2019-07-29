#include <stdio.h>

//같이 주어진 input.txt를 확인하여, output.txt파일의 내용물로 암호화 시켜줄 수 있도록 하여라.
//간단한 암호화 과정에서는 간단한 비트연산자만이 사용되었다.
//hint! , 값을 printf %d와 ascii code를 통해서 어떤 비트연산자가 사용되었는지 간단하게 알 수 있다.
//깔끔하게 값을 출력해내기 위해서 처리해야할 조건이 무엇인지 확인하라.
//본과정의 요구사항은 다음과 같다. 
//같이 주어진 input.txt를 확인하여, output.txt파일의 내용물로 암호화 시켜줄 수 있도록 하여라.

int main(void){
	FILE *in, *out; 
	int n;
	
	in = fopen("input.txt", "r"); 
	out = fopen("output.txt", "a+");
	
	while(/**/){
		/**/
	} 
	
	fclose(in);
	fclose(out);
	
	return 0;
}
