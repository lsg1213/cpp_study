#include <stdio.h>

int main(void){
	FILE *in, *out; 
	int n;
	
	in = fopen("input.txt", "r"); 
	out = fopen("output.txt", "a+");
	
	while(fscanf(in, "%c", &n) != EOF){
		n = ~n;
		fprintf(out, "%d\n", n);
	} 
	
	fclose(in);
	fclose(out);
	
	return 0;
}
