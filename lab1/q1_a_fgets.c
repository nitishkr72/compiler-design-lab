#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 100

int main() {
	FILE * infile;
	char fname[15] = "lab1.txt";
// 	printf("Enter File name: ");
// 	scnaf("%s", fname);
	
	if((infile = fopen(fname, "r")) != NULL) {
		int line=0;
		char rline[BUFF_SIZE];
		while(fgets(rline, BUFF_SIZE, infile))
			printf("%d %s", ++line, rline);
		fclose(infile);
	} else {
		fprintf(stderr, "fopen() failed for '%s'\n", fname);
	}
	return 0;
}
