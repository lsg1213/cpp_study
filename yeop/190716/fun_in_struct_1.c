#include<stdio.h>

typedef struct USERDATA{
	int nAge;
	char szName[12];
	void (*print)(struct USERDATA *);
}USERDATA;

void Print_USERDATA(USERDATA *a){
	printf("%d %s\n", a->nAge, a->szName);
}

int main(){
	USERDATA yeop = { 26, "yeop", Print_USERDATA};

	yeop.print(&yeop);

}
