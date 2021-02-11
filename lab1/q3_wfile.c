#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 100
#define N 10

int main() {
	FILE * infile_dec, * infile_bin;
	char fname_dec[BUFF_SIZE], fname_bin[BUFF_SIZE];

	char sData[N][BUFF_SIZE];

	printf("Enter Name and roll Number eg.'>> Nitish CSB18040'\n");
	int i = 0;
	while(i<N && fgets(sData[i], BUFF_SIZE, stdin))
		i++;

	printf("Enter the filename(saving in text format): ");
	scanf("%s", fname_dec);
	infile_dec = fopen(fname_dec, "w");

	printf("Enter the filename(saving in binary format): ");
	scanf("%s", fname_bin);
	infile_bin = fopen(fname_bin, "wb");

	i = 0;
	while(i < N) {
		fputs(sData[i], infile_dec);
		fwrite(sData[i], BUFF_SIZE, 1, infile_bin);
		i++;
	}

	fclose(infile_dec);
	fclose(infile_bin);

	return 0;
}
