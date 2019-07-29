#include <stdio.h>

int main(void){
	FILE *in, *out; 
	int n;
	
	in = fopen("output.txt", "r"); 
	out = fopen("output1.txt", "a+");
	
	while(fscanf(in, "%d", &n) != EOF){
		n = ~n;
		fprintf(out, "%c", n);
	} 
	
	fclose(in);
	fclose(out);
	
	return 0;
}
