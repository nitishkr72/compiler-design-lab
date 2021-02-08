#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 100

int main() {
	FILE * infile;
	char fname[15] = "lab1.txt";
	infile = fopen(fname, "r");

	int line=0;
	char rline[BUFF_SIZE];
	while(fgets(rline, BUFF_SIZE, infile))
		printf("%d %s", ++line, rline);
	fclose(infile);
	return 0;
}
