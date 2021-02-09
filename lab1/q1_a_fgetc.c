#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE * infile;
	char fname[15] = "lab1.txt";

	if((infile = fopen(fname, "r")) != NULL) {
		int line=0;
		char c = fgetc(infile);
		printf("%d ", ++line);
		while(c != EOF) {
			printf("%c", c);
			if(c == '\n' && (c = fgetc(infile)) != EOF)
				printf("%d ", ++line);
			else
				c = fgetc(infile);
		}
		fclose(infile);
	} else {
		fprintf(stderr, "fopen() failed for '%s'\n", fname);
	}
	return 0;
}
