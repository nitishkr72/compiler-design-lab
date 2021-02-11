#include <stdlib.h>
#include <stdio.h>
#define BUFF_SIZE 100

int isCharValid(unsigned char c) {
	if ((c > 33 && c < 126) || c == 9) {
		return 1;
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		printf("Error.. Enter filename\n");
		return 1;
	}

	char buffer[BUFF_SIZE];
	char * offset = buffer;
	char c;


	FILE * infile;
	if((infile = fopen(argv[1], "r")) != NULL) {
		while((c = fgetc(infile))!= EOF) {
			if(isCharValid(c) && (offset - buffer < sizeof(buffer) - 3)) {
				*offset++ = c;
			} else {
				if(offset - buffer >= 4){
					*offset++ = '\n';
					*offset++ = '\0';

					printf("%s\n", buffer);
				}
				offset = buffer;
			}
		}
		fclose(infile);
	} else {
		printf("Unable of open file\n");
		return 1;
	}

	return 0;
}
