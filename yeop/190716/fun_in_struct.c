#include<stdio.h>
#include<string.h>

typedef struct USERDATA{
	int nAge;
	char szName[10];
	int (*Print)(const struct USERDATA *);
}USERDATA;

int PrintStruct(const USERDATA *a) {
	printf("%d %s\n", a->nAge, a->szName);
	return 1;
}


int main(){
	USERDATA a = {10, "yeop",PrintStruct};
	
	
	PrintStruct(&a);
	int result = a.Print(&a);
	
	printf("%d", result);

}
