#include<stdio.h>

void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = a;
}

int main(){
	int a = 1; int b = 2;
	Swap(a,b);
	printf("%d %d", a, b);
	
}
