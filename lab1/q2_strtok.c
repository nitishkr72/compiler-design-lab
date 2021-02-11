#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100

int main() {
	FILE * infile;
	char fname[BUFF_SIZE];
	printf("Enter file Name: ");
	scanf("%s", fname);

	int fieldNum;
	printf("Enter Field Number: ");
	scanf("%d", &fieldNum);

	char s[2] = " ";
	char *token;

	infile = fopen(fname, "r");
	char line[BUFF_SIZE];
	while(fgets(line, BUFF_SIZE, infile)) {
		
		int count = 1;
		token = strtok(line, s);
		while(token != NULL && count < fieldNum) {
			// printf("%s\n", token);
			token = strtok(NULL, s);
			count++;
		}
		printf("%s\n", token);
	}

	fclose(infile);

	return 0;
}
